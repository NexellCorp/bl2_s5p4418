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
 * Module	: ECID
 * File		: nx_ecid.h
 * Description	:
 * Author	: Sei
 * History	: 
 */
#ifndef __NX_ECID_H__
#define __NX_ECID_H__

#include "nx_prototype.h"

struct  NX_ECID_RegisterSet
{
	u32 ECID[4];           /* 0x00 ~ 0x0C    : 128bit ECID */
	u8  CHIPNAME[48];      /* 0x10 ~ 0x3C    : Chip Name */
	u32 RESERVED;          /* 0x40           : Reserved Region */
	u32 GUID0;             /* 0x44           : GUID 0 */
	u16 GUID1;             /* 0x48           : GUID 1 */
	u16 GUID2;             /* 0x4A           : GUID 2 */
	u8  GUID3[8];          /* 0x4C ~ 0x50    : GUID 3-0 ~ 3-7 */
	u32 EC[3];             /* 0x54 ~ 0x5C    : EC 0 ~ 3 */
};

typedef struct {
	u32 GUID0;
	u16 GUID1;
	u16 GUID2;
	u8  GUID3[8];
} NX_GUID;

/*----------------------------------------------------------------------------*/
enum CS {
	CS_DISABLE = 0,
	CS_ENABLE  = 1
};

enum SIGDEV {
	SIGDEV_DISABLE = 0,
	SIGDEV_ENABLE  = 1
};

enum FSET {
	FSET_DISABLE = 0,
	FSET_ENABLE  = 1
};

enum PRCHG {
	PRCHG_DISABLE = 0,
	PRCHG_ENABLE  = 1
};

#endif /* __NX_ECID_H__ */
