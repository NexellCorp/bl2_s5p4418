/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Module	: Clock Generator
 * File		: nx_clkgen.h
 * Description	:
 * Author	: SoC Team
 * History	:
 */
#ifndef __NX_CLKGEN_H__
#define __NX_CLKGEN_H__

#include "nx_prototype.h"

struct	NX_CLKGEN_RegisterSet {
	u32	clkenb;		/* 0x40 : Clock Enable */
	u32	clkgen[4];	/* 0x44 : Clock Generate */
};

#endif // __NX_CLKGEN_H__
