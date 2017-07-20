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
#define __SET_GLOBAL_VARIABLES

#include "sysheader.h"
#include "nx_bootheader.h"

extern cbool iUSBBOOT(struct NX_SecondBootInfo * pTBI);
extern void launch(cbool, u32, u32, u32);
extern void buildinfo(void);
int sdemmcboot(cbool isresume,
		struct NX_SecondBootInfo *pTBS,
		struct NX_SecondBootInfo *pTBNS,
		struct NX_SecondBootInfo *pTDS);

int plat_load_usbdown(struct nx_bootheader *pBH,
			   struct NX_SecondBootInfo *pTDS,
			   struct NX_SecondBootInfo *pTBS ,
			   struct NX_SecondBootInfo *pTBNS,
			   int is_resume);

void BootMain(cbool isresume, struct nx_bootheader *pBH)
{
	struct NX_SecondBootInfo TBS, TBNS, TDS;
	struct NX_SecondBootInfo *pTDS = &TDS; // secure dispatcher info
	struct NX_SecondBootInfo *pTBS = &TBS; // secure third boot info
	struct NX_SecondBootInfo *pTBNS = &TBNS; // non-secure third boot info
	int ret = CFALSE;
	u32 debug_ch = 0;

//#if defined(AVN) || defined(NAVI) || defined(RAPTOR)
	debug_ch = 3;
//#endif

#if 1
	DebugInit(debug_ch);
#endif
	buildinfo();

	switch (pSBI->DBI.SPIBI.LoadDevice) {
	default:
#if defined(SUPPORT_USB_BOOT)
	case BOOT_FROM_USB:
		NOTICE("Loading from_usb... %d\r\n", isresume);
		ret = plat_load_usbdown((struct nx_bootheader *)pBH,
			(struct NX_SecondBootInfo *)pTDS,
			(struct NX_SecondBootInfo *)pTBS,
			(struct NX_SecondBootInfo *)pTBNS, isresume);
		break;
#endif

#if defined(SUPPORT_SDMMC_BOOT)
	case BOOT_FROM_SDMMC:
		NOTICE("Loading from sdmmc... %d\r\n", isresume);
		ret = sdemmcboot(isresume, pTDS, pTBS, pTBNS);
		break;
#endif
	}

	if (ret) {
		NOTICE(" Image Loading Done!\r\n");
		NOTICE("Launch to 0x%08X\r\n", pTDS->LAUNCHADDR);
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

	ERROR("Image Loading Failure Try to USB boot\r\n");
	while (!DebugIsUartTxDone())
		;
}
