/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Module	: Reset Generator
 * File		: nx_rstcon.h
 * Description	:
 * Author	: SoC Team
 * History	:
 */
#ifndef __NX_RSTCON_H__
#define __NX_RSTCON_H__

#include "nx_prototype.h"

#define __def_RSTCON__RSTREGISTERCNT 1


struct	NX_RSTCON_RegisterSet {
	volatile u32	REGRST[__def_RSTCON__RSTREGISTERCNT + 1];
};

typedef enum {
	RSTCON_nDISABLE = 0UL,
	RSTCON_nENABLE	= 1UL
}RSTCON_nRST;

typedef enum {
	RSTCON_ENABLE	= 1UL,
	RSTCON_DISABLE	= 0UL
}RSTCON_RST;

#endif /* __NX_RSTCON_H__ */
