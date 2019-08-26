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
#ifndef __CFG_FREQ_DEFINE_H__
#define __CFG_FREQ_DEFINE_H__

//------------------------------------------------------------------------------
//	oscilator
//------------------------------------------------------------------------------
#define OSC_HZ              (24000000)
#define OSC_KHZ             (OSC_HZ/1000)
#define OSC_MHZ             (OSC_KHZ/1000)

#define NX_CLKSRC_PLL_0     (0)
#define NX_CLKSRC_PLL_1     (1)
#define NX_CLKSRC_PLL_2     (2)
#define NX_CLKSRC_PLL_3     (3)


//------------------------------------------------------------------------------
#define NX_CLKSRC_UART      (NX_CLKSRC_PLL_0)
#ifdef QUICKBOOT
#define NX_CLKSRC_SDMMC     (NX_CLKSRC_PLL_0)
#else
#define NX_CLKSRC_SDMMC     (NX_CLKSRC_PLL_2)
#endif
#define NX_CLKSRC_SPI       (NX_CLKSRC_PLL_0)

#endif  /* __CFG_FREQ_DEFINE_H__ */
