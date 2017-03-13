/*
 * Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
 * Nexell Co. Proprietary & Confidential
 *
 * Nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular puporse.
 * 
 * Module	: print
 * File		: printf.h
 * Description	:
 * Author	: Hans
 * History	: 2017.02.28 new release
 */
#ifndef __K_PRINTF__
#define __K_PRINTF__

#include <stdarg.h>
#include "debug.h"

#define putchar DebugPutch

int printf(const char *format, ...);

#endif
