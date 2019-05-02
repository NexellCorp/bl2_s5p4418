/*
 * Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
 * Nexell Co. Proprietary & Confidential
 *
 * Nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular puporse.
 * This code is not allowed to be redelivered or released to the public
 * without permission.
 * 
 * Module	: bl2
 * File		: sysheader.h
 * Description	:
 * Author	: Hans
 * History	: 2017.02.28 new release
 */
#ifndef __SYS_HEADER_H__
#define __SYS_HEADER_H__

#include "cfgFreqDefine.h"

#include <nx_pyrope.h>
#include <nx_type.h>
#include <nx_chip.h>

#include <nx_gpio.h>
#include <nx_tieoff.h>

#include "bl2.h"
#include "printf.h"
#include "debug.h"
#include <common.h>

//------------------------------------------------------------------------------
//  Set DEBUG Macro
//------------------------------------------------------------------------------

#if 0 // def NX_DEBUG
#define SYSMSG printf
#else
#define SYSMSG(x, ...)
#endif

// Memory debug message
#if 0
#define MEMMSG  printf
#else
#define MEMMSG(x, ...)
#endif

// UserDebug Message
#if 0
#define DBGOUT  printf
#else
#define DBGOUT(x, ...)
#endif

//------------------------------------------------------------------------------
//  Set global variables
//------------------------------------------------------------------------------
#ifdef OTA_AB_UPDATE
/* see, partmap.txt */
/* bootloader_a start address = 0x10200 */
/* bootloader_b start address = 0x4D0200 */
/* offset = addr of slot B  -  addr of slot A */
/*        = 0x4D0200 - 0x10200 */
/*        = 0x4C0000 */
#define OTA_UPDATE_BL2_ADDR_OFFSET_A            (0)
#define OTA_UPDATE_BL2_ADDR_OFFSET_B            (0x4C0000)
#define OTA_AB_UPDATE_BL2_MSG_A                 (0xAAAAAAAA)
#define OTA_AB_UPDATE_BL2_MSG_B                 (0xBBBBBBBB)
#endif

#if defined(__SET_GLOBAL_VARIABLES)

struct NX_SecondBootInfo *const pSBI =
	(struct NX_SecondBootInfo *const)BASEADDR_SRAM;
volatile struct NX_GPIO_RegisterSet (*const pReg_GPIO)[1] =
	(struct NX_GPIO_RegisterSet (*const)[])PHY_BASEADDR_GPIOA_MODULE;
volatile struct NX_TIEOFF_RegisterSet *const pReg_Tieoff =
	(struct NX_TIEOFF_RegisterSet *const)PHY_BASEADDR_TIEOFF_MODULE;
#else

extern struct NX_SecondBootInfo *const pSBI; // second boot info
extern volatile struct NX_GPIO_RegisterSet (*const pReg_GPIO)[1];
extern volatile struct NX_TIEOFF_RegisterSet *const pReg_Tieoff;
#endif

#endif //	__SYS_HEADER_H__
