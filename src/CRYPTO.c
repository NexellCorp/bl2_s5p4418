/*
 * Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
 * Nexell Co. Proprietary & Confidential
 *
 * Nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular puporse.
 * 
 * Module	:
 * File		:
 * Description	:
 * Author	: Hans
 * History	: 2017.02.28 new release
 */
#include <nx_pyrope.h>
#include "sysheader.h"
#include "nx_crypto.h"
#include "nx_clkgen.h"
#include "nx_ecid.h"

void ResetCon(u32 devicenum, cbool en);

static volatile struct NX_ECID_RegisterSet *const pECIDReg =
	(struct NX_ECID_RegisterSet *)PHY_BASEADDR_ECID_MODULE;
static volatile struct NX_CLKGEN_RegisterSet *const pCryptoClkGenReg =
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN34_MODULE;
static volatile struct NX_CRYPTO_RegisterSet *const pCrypto =
	(struct NX_CRYPTO_RegisterSet *)PHY_BASEADDR_CRYPTO_MODULE;

void Decrypt(u32 *SrcAddr, u32 *DestAddr, u32 Size, u8* key)
{
	register u32 i = 0, DataSize = ((Size + 15) & 0xFFFFFFF0);
	u32 *bigkey = (u32*)key;
	ResetCon(RI_ECID_MODULE_i_nRST, CTRUE);		/* reset on */
	ResetCon(RI_ECID_MODULE_i_nRST, CFALSE);	/* reset negate */

	while (!(pECIDReg->EC[2] & 0x1 << 15))	/* wait for ecid ready */
		;

	ResetCon(RI_CRYPTO_MODULE_i_nRST, CTRUE);	/* reset on */
	ResetCon(RI_CRYPTO_MODULE_i_nRST, CFALSE);	/* reset negate */

	pCryptoClkGenReg->clkenb = 1 << 3;	/* pclk always mode. */

	if (bigkey != 0) {
		pCrypto->CRYPTO_AES_KEY[0] = bigkey[0];
		pCrypto->CRYPTO_AES_KEY[1] = bigkey[1];
		pCrypto->CRYPTO_AES_KEY[2] = bigkey[2];
		pCrypto->CRYPTO_AES_KEY[3] = bigkey[3];
	}

	while (i < (DataSize >> 2)) {	/* 128bits == 4bytes x 4 */
		u32 j, temp[4], ctrl;
		u8 *LittleEndian, *BigEndian;
		ctrl =  0x0 << 15 | /* 0: Enable, 1: Disable  Use Fuse Key */
			0x1 << 9 |  /* 0: Big Endian, 1: Little Endian output swap */
			0x1 << 8 |  /* 0: Big Endian, 1: Little Endian input swap */
			0x0 << 6 |  /* 0: ECB, 1: CBC, 2: CTR mode */
			0x1 << 3 |  /* 64bit counter */
			0x0 << 2 |  /* 0: FIFO Mode, 1: DMA Mode */
			0x0 << 1 |  /* 0: Decoder, 1: Encoder */
			0x0 << 0;   /* 0: Disable, 1: Enable AES Enable? */
		if (bigkey == 0)
			ctrl |= 0x1 << 15;
		pCrypto->CRYPTO_AES_CTRL0 = ctrl;

		LittleEndian = (u8*)&SrcAddr[i];
		BigEndian = (u8*)temp;
		for (j = 0; j < 16; j++)
			BigEndian[j] = LittleEndian[15 - j];

		pCrypto->CRYPTO_AES_TIN[0] = temp[3];
		pCrypto->CRYPTO_AES_TIN[1] = temp[2];
		pCrypto->CRYPTO_AES_TIN[2] = temp[1];
		pCrypto->CRYPTO_AES_TIN[3] = temp[0];

		ctrl =  0x0 << 15 | /* 0: Enable, 1: Disable  Use Fuse Key */
			0x1 << 9 |  /* 0: Big Endian, 1: Little Endian output swap */
			0x1 << 8 |  /* 0: Big Endian, 1: Little Endian input swap */
			0x0 << 6 |  /* 0: ECB, 1: CBC, 2: CTR mode */
			0x1 << 3 |  /* 64bit counter */
			0x0 << 2 |  /* 0: FIFO Mode, 1: DMA Mode */
			0x0 << 1 |  /* 0: Decoder, 1: Encoder */
			0x1 << 0;   /* 0: Disable, 1: Enable AES Enable? */

		if (bigkey == 0)
			ctrl |= 0x1 << 15;
		pCrypto->CRYPTO_AES_CTRL0 = ctrl;

		pCrypto->CRYPTO_CRT_CTRL0 |= 0x1 << 0; /* Decryption run */

		while (!(pCrypto->CRYPTO_CRT_CTRL0 & 0x1 << 1))
			;

		temp[3] = pCrypto->CRYPTO_AES_TOUT[0];
		temp[2] = pCrypto->CRYPTO_AES_TOUT[1];
		temp[1] = pCrypto->CRYPTO_AES_TOUT[2];
		temp[0] = pCrypto->CRYPTO_AES_TOUT[3];

		LittleEndian = (u8*)&DestAddr[i];
		BigEndian = (u8*)temp;
		for (j = 0; j < 16; j++)
			LittleEndian[j] = BigEndian[15 - j];

		i += 4;
	}
}
