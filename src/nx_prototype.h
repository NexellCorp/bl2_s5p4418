/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Module	: Base
 * File		: nx_prototype.h
 * Description	: Goofy
 * Author	: 
 * History	: 
 * 2012-07-25  Tony    append PHY_BASEADDR_LIST_ALPHA( x ) : alphabetic version.
 * 2012-06-27  Gamza   append PHY_BASEADDR_LIST( x )
 * 2010.10.05  Hans    add global io access function
 * 2010.04.27  Hans
 * 2007.04.04  Goofy   First draft
 */
#ifndef __NX_PROTOTYPE_H__
#define __NX_PROTOTYPE_H__

#include "nx_type.h"
#include "nx_debug.h"
#include "nx_chip.h"
#include "nx_clockcontrol.h"

#define RIO32(Addr)		(*(volatile u32 *)(Addr))
#define RIO16(Addr)		(*(volatile u16 *)(Addr))
#define RIO8(Addr)		(*(volatile u8  *)(Addr))

#define WIO32(Addr,Data)	(*(volatile u32 *)(Addr))  =  ((u32)(Data))
#define WIO16(Addr,Data)	(*(volatile u16 *)(Addr))  =  ((u16)(Data))
#define WIO8(Addr,Data)		(*(volatile u8  *)(Addr))  =  ((u8 )(Data))

#define SIO32(Addr,Data)	(*(volatile u32 *)(Addr)) |=  ((u32)(Data))
#define SIO16(Addr,Data)	(*(volatile u16 *)(Addr)) |=  ((u16)(Data))
#define SIO8(Addr,Data)		(*(volatile u8  *)(Addr)) |=  ((u8 )(Data))

#define CIO32(Addr,Data)	(*(volatile u32 *)(Addr)) &= ~((u32)(Data))
#define CIO16(Addr,Data)	(*(volatile u16 *)(Addr)) &= ~((u16)(Data))
#define CIO8(Addr,Data)		(*(volatile u8  *)(Addr)) &= ~((u8 )(Data))


#endif  /* __NX_PROTOTYPE_H__ */
