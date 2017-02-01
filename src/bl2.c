/*
 * Copyright (C) 2016  Nexell Co., Ltd.
 * Author: Sangjong, Han <hans@nexell.co.kr>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#define __SET_GLOBAL_VARIABLES

#include "sysheader.h"
#include "nx_bootheader.h"

extern void DMC_Delay(int milisecond);
extern void ResetCon(U32 devicenum, CBOOL en);

extern CBOOL iUSBBOOT(struct NX_SecondBootInfo * pTBI);
extern CBOOL iSDXCBOOT(struct NX_SecondBootInfo * pTBI);
extern void launch(CBOOL, U32, U32, U32);
extern void buildinfo(void);
int sdemmcboot(CBOOL isresume,
		struct NX_SecondBootInfo *pTBS,
		struct NX_SecondBootInfo *pTBNS,
		struct NX_SecondBootInfo *pTDS);

extern int CRC_Check(void* buf, unsigned int size, unsigned int ref_crc);

void enableL2Cache(unsigned int enb)
{
	unsigned int reg;

	// L2 Cache
	reg = ReadIO32(&pReg_Tieoff->TIEOFFREG[0]);
	if (enb)
		reg |= (3UL << 12);
	else
		reg &= ~(3UL << 12);

	WriteIO32(&pReg_Tieoff->TIEOFFREG[0], reg);
}

void BootMain(CBOOL isresume, struct nx_bootheader *pBH)
{
	struct NX_SecondBootInfo TBS, TBNS, TDS;
	struct NX_SecondBootInfo *pTDS = &TDS; // secure dispatcher info
	struct NX_SecondBootInfo *pTBS = &TBS; // secure third boot info
	struct NX_SecondBootInfo *pTBNS = &TBNS; // non-secure third boot info
	int ret = CFALSE;
	U32 debug_ch = 0;

//#if defined(AVN) || defined(NAVI) || defined(RAPTOR)
	debug_ch = 3;
//#endif

#if 1 // Low Level Debug Message
	/*  Low Level Debug Message */
	DebugInit(debug_ch);
#endif
	/* Build information */
	buildinfo();

	switch (pSBI->DBI.SPIBI.LoadDevice) {
	default:
#if defined(SUPPORT_USB_BOOT)
	case BOOT_FROM_USB:
		printf("Loading dispatcher from usb...\r\n");
		ret = iUSBBOOT(pTDS);	// for USB boot
		if (!isresume) {
			printf("Loading Secure OS from usb...\r\n");
			ret = iUSBBOOT(pTBS);	// for USB boot
			printf("Loading U-Boot from usb...\r\n");
			ret = iUSBBOOT(pTBNS);	// for USB boot
		}
		break;
#endif

#if defined(SUPPORT_SDMMC_BOOT)
	case BOOT_FROM_SDMMC:
		printf("Loading from sdmmc... %d\r\n", isresume);
		ret = sdemmcboot(isresume, pTDS, pTBS, pTBNS);
		break;
#endif
	}

	if (ret) {
		printf(" Image Loading Done!\r\n");
		printf("Launch to 0x%08X\r\n", pTDS->LAUNCHADDR);
		while (!DebugIsUartTxDone())
			;
		if (isresume) {
			pTBS->LAUNCHADDR = pBH->tbbi._reserved320;
			pTBNS->LAUNCHADDR = pBH->tbbi._reserved321;
		} else {
			pBH->tbbi._reserved320 = pTBS->LAUNCHADDR;
			pBH->tbbi._reserved321 = pTBNS->LAUNCHADDR;
		}
		while (!DebugIsUartTxDone())
			;
		launch(isresume, pTBS->LAUNCHADDR,
				pTBNS->LAUNCHADDR,
				pTDS->LAUNCHADDR);
	}

	printf("Image Loading Failure Try to USB boot\r\n");
	while (!DebugIsUartTxDone());
}
