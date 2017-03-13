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

#include <nx_type.h>
#include <nx_chip.h>
#include <nx_gpio.h>

struct NXPYROPE_GPIO_RegSet {
	struct NX_GPIO_RegisterSet NXGPIO;
	u8 Reserved[0x1000 - sizeof(struct NX_GPIO_RegisterSet)];
};

#if !DIRECT_IO
static volatile struct NXPYROPE_GPIO_RegSet (*const pBaseGPIOReg)[1] =
	(struct NXPYROPE_GPIO_RegSet(*)[])(PHY_BASEADDR_GPIOA_MODULE);
void GPIOSetAltFunction(u32 AltFunc)
{
	register volatile struct NX_GPIO_RegisterSet *pGPIOReg =
		&pBaseGPIOReg[(AltFunc >> 8) & 0x7]->NXGPIO;
	pGPIOReg->GPIOxALTFN[(AltFunc >> 7) & 0x1] =
		(pGPIOReg->GPIOxALTFN[(AltFunc >> 7) & 0x1] &
		 ~(0x3UL << (((AltFunc >> 3) & 0xF) * 2))) |
		((AltFunc & 0x3) << (((AltFunc >> 3) & 0xF) * 2));
}
#endif
