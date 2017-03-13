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
#include "nx_type.h"
#include "nx_chip.h"
#include "nx_rstcon.h"

static volatile struct NX_RSTCON_RegisterSet *const pReg_RstCon =
	(struct NX_RSTCON_RegisterSet *)PHY_BASEADDR_RSTCON_MODULE;
static u32 RESET_IDX_LIST[2] = {
	RI_TIMER_MODULE_PRESETn,
	RI_PWM_MODULE_PRESETn
};

void ResetCon(u32 devicenum, cbool en)
{
	if (en)
		CIO32(&pReg_RstCon->REGRST[(devicenum >> 5) & 0x3],
			  (0x1 << (devicenum & 0x1F))); // reset
	else
		SIO32(&pReg_RstCon->REGRST[(devicenum >> 5) & 0x3],
			(0x1 << (devicenum & 0x1F))); // reset negate
}

void device_reset(void)
{
	u32 i;
	for (i = 0; i < (sizeof(RESET_IDX_LIST) / sizeof(u32)); i++) {
		ResetCon(RESET_IDX_LIST[i], CTRUE);	// reset on
		ResetCon(RESET_IDX_LIST[i], CFALSE);	// reset negate
	}
}

