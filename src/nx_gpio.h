/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS
 * FOR A PARTICULAR PURPOSE.
 * 
 * Module	: GPIO
 * File		: nx_gpio.h
 * Description	:
 * Author	: Firmware Team
 * History	: 
 */
#ifndef __NX_GPIO_H__
#define __NX_GPIO_H__

#include "nx_prototype.h"

struct	NX_GPIO_RegisterSet {
	u32 GPIOxOUT;		/* 0x00 : Output */
	u32 GPIOxOUTENB;	/* 0x04 : Output Enable */
	u32 GPIOxDETMODE[2];	/* 0x08 : Event Detect Mode */
	u32 GPIOxINTENB;	/* 0x10 : Interrupt Enable */
	u32 GPIOxDET;		/* 0x14 : Event Detect */
	u32 GPIOxPAD;		/* 0x18 : PAD Status */
	u32 GPIOxPUENB;		/* 0x1C : Pull Up Enable */
	u32 GPIOxALTFN[2];	/* 0x20 : Alternate Function Select */
	u32 GPIOxDETMODEEX;	/* 0x28 : Event Detect Mode extended */

	u32 __Reserved[4];	/* 0x2B : */
	u32 GPIOxDETENB;	/* 0x3C : IntPend Detect Enable */

	u32 GPIOx_SLEW;		/* 0x40 : Slew Register */
	u32 GPIOx_SLEW_DD;	/* 0x44 : Slew set On/Off */
	u32 GPIOx_DRV1;		/* 0x48 : drive strength LSB */
	u32 GPIOx_DRV1_DD;	/* 0x4C : drive strength LSB set On/Off */
	u32 GPIOx_DRV0;		/* 0x50 : drive strength MSB */
	u32 GPIOx_DRV0_DD;	/* 0x54 : drive strength MSB set On/Off */
	u32 GPIOx_PULLSEL;	/* 0x58 : Pull UP/DOWN Selection */
	u32 GPIOx_PULLSEL_DD;	/* 0x5C : Pull UP/DOWN Selection On/Off */
	u32 GPIOx_PULLENB;	/* 0x60 : Pull Enable/Disable */
	u32 GPIOx_PULLENB_DD;	/* 0x64 : Pull Enable/Disable selection On/Off */
	u32 GPIOx_InputMuxSel0;	/* 0x68 */
	u32 GPIOx_InputMuxSel1;	/* 0x6C */
	u8 __Reserved1[0x1000-0x70];
};

enum {
	NX_GPIO_INT0	= 0,
	NX_GPIO_INT1	= 1,
	NX_GPIO_INT2	= 2,
	NX_GPIO_INT3	= 3,
	NX_GPIO_INT4	= 4,
	NX_GPIO_INT5	= 5,
	NX_GPIO_INT6	= 6,
	NX_GPIO_INT7	= 7,
	NX_GPIO_INT8	= 8,
	NX_GPIO_INT9	= 9,
	NX_GPIO_INT10	= 10,
	NX_GPIO_INT11	= 11,
	NX_GPIO_INT12	= 12,
	NX_GPIO_INT13	= 13,
	NX_GPIO_INT14	= 14,
	NX_GPIO_INT15	= 15,
	NX_GPIO_INT16	= 16,
	NX_GPIO_INT17	= 17,
	NX_GPIO_INT18	= 18,
	NX_GPIO_INT19	= 19,
	NX_GPIO_INT20	= 20,
	NX_GPIO_INT21	= 21,
	NX_GPIO_INT22	= 22,
	NX_GPIO_INT23	= 23,
	NX_GPIO_INT24	= 24,
	NX_GPIO_INT25	= 25,
	NX_GPIO_INT26	= 26,
	NX_GPIO_INT27	= 27,
	NX_GPIO_INT28	= 28,
	NX_GPIO_INT29	= 29,
	NX_GPIO_INT30	= 30,
	NX_GPIO_INT31	= 31
};

typedef enum {
	NX_GPIO_INTMODE_LOWLEVEL	= 0UL,
	NX_GPIO_INTMODE_HIGHLEVEL	= 1UL,
	NX_GPIO_INTMODE_FALLINGEDGE	= 2UL,
	NX_GPIO_INTMODE_RISINGEDGE	= 3UL,
	NX_GPIO_INTMODE_BOTHEDGE	= 4UL
} NX_GPIO_INTMODE;

typedef enum {
	NX_GPIO_PADFUNC_0		= 0UL,
	NX_GPIO_PADFUNC_1		= 1UL,
	NX_GPIO_PADFUNC_2		= 2UL,
	NX_GPIO_PADFUNC_3		= 3UL
} NX_GPIO_PADFUNC;

typedef enum {
	NX_GPIO_DRVSTRENGTH_0		= 0UL,
	NX_GPIO_DRVSTRENGTH_1		= 1UL,
	NX_GPIO_DRVSTRENGTH_2		= 2UL,
	NX_GPIO_DRVSTRENGTH_3		= 3UL

} NX_GPIO_DRVSTRENGTH;

typedef enum {
	NX_GPIO_PULL_DOWN		= 0UL,
	NX_GPIO_PULL_UP			= 1UL,
	NX_GPIO_PULL_OFF		= 2UL
} NX_GPIO_PULL;

#endif /*__NX_GPIO_H__*/
