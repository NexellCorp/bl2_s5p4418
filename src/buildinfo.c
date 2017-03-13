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
#include "sysheader.h"
//------------------------------------------------------------------------------
cbool buildinfo(void)
{
	cbool ret = CTRUE;

	printf("\r\n"
"------------------------------------------------------------\r\n"
" BL2 by Nexell Co. - Built on %s %s\r\n"
"------------------------------------------------------------\r\n"
	, __DATE__, __TIME__);

	return ret;
}
