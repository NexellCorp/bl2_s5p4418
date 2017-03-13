/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Module	: Clock & Power Manager
 * File		: nx_clkpwr.h
 * Description	:
 * Author	: Firmware Team
 * History	:
 */

#ifndef __NX_CLKPWR_H__
#define __NX_CLKPWR_H__

#include "nx_prototype.h"

/*------------------------*/
/* implentation of ALIVE */
/*------------------------*/
#define NUMBER_OF_ALIVE_MODULE 1
#define PHY_BASEADDR_ALIVE_MODULE	(PHY_BASEADDR_CLKPWR_MODULE + 0x800)  /* 2048 */

#define NUMBER_OF_RTC_MODULE 1
#define PHY_BASEADDR_RTC_MODULE		(PHY_BASEADDR_CLKPWR_MODULE + 0xc00) /* 2048+1024 */

#define NUMBER_OF_PMU_MODULE 1
#define PHY_BASEADDR_PMU_MODULE		(PHY_BASEADDR_CLKPWR_MODULE + 0xc00 + 0x100)  /* 2048+256 */


#define INTNUM_OF_RTC_MODULE          INTNUM_OF_CLKPWR_MODULE_RTCIRQ
#define INTNUM_OF_ALIVE_MODULE        INTNUM_OF_CLKPWR_MODULE_ALIVEIRQ
#define INTNUM_OF_CLKPWR_MODULE       INTNUM_OF_CLKPWR_MODULE_INTREQPWR

#define NUMBER_OF_PMU_POWER_DOMAIN 2

struct	NX_CLKPWR_RegisterSet {
	u32 CLKMODEREG0;		/* 0x000 : Clock Mode 0 */
	u32 __Reserved0;		/* 0x004 */
	u32 PLLSETREG[4];		/* 0x008 ~ 0x014 : PLL Setting */
	u32 __Reserved1[2];		/* 0x018 ~ 0x01C */
	u32 DVOREG[5];			/* 0x020 ~ 0x030 : Divider Setting */
	u32 __Reserved2[5];		/* 0x034 ~ 0x044 */
	u32 PLLSETREG_SSCG[6];		/* 0x048 ~ 0x05C */
	u32 __reserved3[8];		/* 0x060 ~ 0x07C */
	u32 __Reserved4[(512-128)/4];	/* padding (0x200-..)/4 */
	u32 GPIOWAKEUPRISEENB;		/* 0x200 : GPIO Rising Edge Detect Enable */
	u32 GPIOWAKEUPFALLENB;		/* 0x204 : GPIO Falling Edge Detect Enable */
	u32 GPIORSTENB;			/* 0x208 : GPIO Reset Enable */
	u32 GPIOWAKEUPENB;		/* 0x20C : GPIO Wakeup Source Enable */
	u32 GPIOINTENB;			/* 0x210 : Interrupt Enable */
	u32 GPIOINTPEND;		/* 0x214 : Interrupt Pend */
	u32 RESETSTATUS;		/* 0x218 : Reset Status */
	u32 INTENABLE;			/* 0x21C : Interrupt Enable */
	u32 INTPEND;			/* 0x220 : Interrupt Pend */
	u32 PWRCONT;			/* 0x224 : Power Control */
	u32 PWRMODE;			/* 0x228 : Power Mode */
	u32 __Reserved5;		/* 0x22C : Reserved Region */
	u32 SCRATCH[3];			/* 0x230 ~ 0x238 : Scratch */
	u32 SYSRSTCONFIG;		/* 0x23C : System Reset Configuration */
	u8  __Reserved6[0x100-0x80];	/* 0x80 ~ 0xFC	: Reserved Region */
	u32 PADSTRENGTHGPIO[5][2];	/* 0x100, 0x104 : GPIOA Pad Strength */
	       				/* 0x108, 0x10C : GPIOB Pad Strength */
	       				/* 0x110, 0x114 : GPIOC Pad Strength */
	       				/* 0x118, 0x11C : GPIOD Pad Strength */
	       				/* 0x120, 0x124 : GPIOE Pad Strength */
	u32 __Reserved7[2];		/* 0x128 ~ 0x12C: Reserved Region */
	u32 PADSTRENGTHBUS;		/* 0x130 : Bus Pad Strength */
};

enum {
	NX_CLKPWR_INT_ALIVEGPIO0	= 0,	/* ALIVE GPIO 0 */
	NX_CLKPWR_INT_ALIVEGPIO1	= 1,	/* ALIVE GPIO 1 */
	NX_CLKPWR_INT_ALIVEGPIO2	= 2,	/* ALIVE GPIO 2 */
	NX_CLKPWR_INT_ALIVEGPIO3	= 3,	/* ALIVE GPIO 3 */
	NX_CLKPWR_INT_ALIVEGPIO4	= 4,	/* ALIVE GPIO 4 */
	NX_CLKPWR_INT_ALIVEGPIO5	= 5,	/* ALIVE GPIO 5 */
	NX_CLKPWR_INT_VDDTOGGLE		= 6,	/* VDD Power Toggle*/
	NX_CLKPWR_INT_UART0		= 7,	/* UART RX 0 */
	NX_CLKPWR_INT_UART1		= 8,	/* UART RX 1 */
	NX_CLKPWR_INT_UART2		= 9,	/* UART RX 2 */
	NX_CLKPWR_INT_UART3		=10,	/* UART RX 3 */
	NX_CLKPWR_INT_UART4		=11,	/* UART RX 4 */
	NX_CLKPWR_INT_UART5		=12,	/* UART RX 5 */
	NX_CLKPWR_INT_USB0		=13,	/* USB  0 */
	NX_CLKPWR_INT_USB1		=14,	/* USB  1 */
	NX_CLKPWR_INT_RTC		=15,	/* RTC */
	NX_CLKPWR_INT_BATF		=16,	/* Battery fault event */
	NX_CLKPWR_INT_MAX		=17
};

enum {
	NX_CLKPWR_RESETSTATUS_POWERON		= 1 << 0,	/* Power on */
	NX_CLKPWR_RESETSTATUS_GPIO		= 1 << 1,	/* GPIO */
	NX_CLKPWR_RESETSTATUS_WATCHDOG		= 1 << 2,	/* Watchdog */
	NX_CLKPWR_RESETSTATUS_SOFTWARE		= 1 << 3,	/* Software */
	NX_CLKPWR_RESETSTATUS_DSLEEPRESET	= 1 << 4,	/* Deep Sleep */
	NX_CLKPWR_RESETSTATUS_SLEEPRESET	= 1 << 5,	/* Sleep */
}	NX_CLKPWR_RESETSTATUS;

enum {
	NX_CLKPWR_POWERMODE_STOP		= 1 << 5,	/* Stop mode */
	NX_CLKPWR_POWERMODE_IDLE		= 1 << 4	/* Idle mode */
}	NX_CLKPWR_POWERMODE;

enum {
	NX_CLKPWR_BUSPAD_STATIC_CNTL	= 22UL,		/* Static Control */
	NX_CLKPWR_BUSPAD_STATIC_ADDR	= 20UL,		/* Static Address */
	NX_CLKPWR_BUSPAD_STATIC_DATA	= 18UL,		/* Static Data */
	NX_CLKPWR_BUSPAD_VSYNC		= 6UL,		/* Vertical Sync */
	NX_CLKPWR_BUSPAD_HSYNC		= 4UL,		/* Horizontal Sync */
	NX_CLKPWR_BUSPAD_DE		= 2UL,		/* Data Enable */
}	NX_CLKPWR_BUSPAD;

enum {
	NX_CLKPWR_PLL_0	= 0UL,		/* pll number 0 */
	NX_CLKPWR_PLL_1	= 1UL,		/* pll number 1 */
	NX_CLKPWR_PLL_2	= 2UL,		/* pll number 2 */
	NX_CLKPWR_PLL_3 = 3UL,		/* pll number 3 */
}	NX_CLKPWR_PLL;

enum {
	NX_CLKPWR_CLOCK_FCLK		= 0UL,		/* clock divider FCLK */
	NX_CLKPWR_CLOCK_BCLK		= 1UL,		/* clock divider BCLK */
	NX_CLKPWR_CLOCK_MCLK		= 2UL,		/* clock divider MCLK */
	NX_CLKPWR_CLOCK_GR3DBCLK	= 3UL,		/* clock divider GR3DBCLK */
	NX_CLKPWR_CLOCK_MPEGBCLK	= 4UL,		/* clock divider MPEGBCLK */
}	NX_CLKPWR_CLOCK;


enum {
	NX_CLKPWR_GMUX_XTAL	= 0UL,		/* PLL's out-mux to Xrystal */
	NX_CLKPWR_GMUX_PLL	= 1UL,		/* PLL's out-mux to PLL */
}	NX_CLKPWR_GMUX;

enum {
	NX_CLKPWR_POWER_SWITCH_PRECHARGE	= 0UL,	/* pre discharge power switch */
	NX_CLKPWR_POWER_SWITCH_ALL		= 1UL,	/* all power switch */
}	NX_CLKPWR_POWER_SWITCH;

enum {
	NX_CLKPWR_POWER_DOMAIN_0	= 0UL,	/* power domain 0 */
	NX_CLKPWR_POWER_DOMAIN_1	= 1UL,	/* power domain 1 */
}	NX_CLKPWR_POWER_DOMAIN;


enum {
	NX_CLKPWR_PLL_POWER_UP  	= 0UL,	/* power domain 0 */
	NX_CLKPWR_PLL_POWER_DOWN	= 1UL,	/* power domain 1 */
}	NX_CLKPWR_PLL_POWER;

#define PLL_P   18
#define PLL_M   8
#define PLL_S   0

#define PLL_K   16

#endif // __NX_CLKPWR_H__
