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
#include "nx_clkgen.h"
#include "nx_uart.h"

#define UARTSRC 		2
#define SOURCE_DIVID		(4UL)
#define BAUD_RATE 		(115200)

void ResetCon(u32 devicenum, cbool en);
void GPIOSetAltFunction(u32 AltFunc);
u32 NX_CLKPWR_GetPLLFrequency(u32 PllNumber);

static volatile struct NX_UART_RegisterSet *pReg_Uart;

static const u32 UARTBASEADDR[] = {
	PHY_BASEADDR_UART0_MODULE, 
	PHY_BASEADDR_pl01115_Uart_modem_MODULE,
	PHY_BASEADDR_UART1_MODULE, 
	PHY_BASEADDR_pl01115_Uart_nodma0_MODULE,
	PHY_BASEADDR_pl01115_Uart_nodma1_MODULE
};
static const u32 UARTCLKGENADDR[] = {
	PHY_BASEADDR_CLKGEN22_MODULE, 
	PHY_BASEADDR_CLKGEN24_MODULE,
	PHY_BASEADDR_CLKGEN23_MODULE, 
	PHY_BASEADDR_CLKGEN25_MODULE,
	PHY_BASEADDR_CLKGEN26_MODULE
};

static const u8 RESETNUM[] = {
	RI_UART0_MODULE_nUARTRST,
	RI_pl01115_Uart_modem_MODULE_nUARTRST,
	RI_UART1_MODULE_nUARTRST,
	RI_pl01115_Uart_nodma0_MODULE_nUARTRST,
	RI_pl01115_Uart_nodma1_MODULE_nUARTRST
};

static const u32 GPIOALTNUM[] = {
	PI_UART0_UARTRXD,
	PI_UART0_UARTTXD,
	PI_pl01115_Uart_modem_UARTRXD,
	PI_pl01115_Uart_modem_UARTTXD, 
	PI_UART1_UARTRXD,
	PI_UART1_UARTTXD, 
	PI_pl01115_Uart_nodma0_UARTRXD,
	PI_pl01115_Uart_nodma0_UARTTXD,
	PI_pl01115_Uart_nodma1_UARTRXD,
	PI_pl01115_Uart_nodma1_UARTTXD,
};
static const u32 UARTSMC[] = {
	TI_UART0_USESMC,
	TI_UART0_SMCTXENB,
	TI_UART0_SMCRXENB,
	TI_UART_MODEM0_USESMC,
	TI_UART_MODEM0_SMCTXENB,
	TI_UART_MODEM0_SMCRXENB,
	TI_UART1_USESMC,
	TI_UART1_SMCTXENB,
	TI_UART1_SMCRXENB,
	TI_UART_NODMA0_USESMC,
	TI_UART_NODMA0_SMCTXENB,
	TI_UART_NODMA0_SMCRXENB,
	TI_UART_NODMA1_USESMC,
	TI_UART_NODMA1_SMCTXENB,
	TI_UART_NODMA1_SMCRXENB
};

cbool DebugInit(u32 ch)
{
	u32 SOURCE_CLOCK;
	volatile struct NX_CLKGEN_RegisterSet *const pReg_UartClkGen =
		(struct NX_CLKGEN_RegisterSet *)UARTCLKGENADDR[ch];

	pReg_Uart = (struct NX_UART_RegisterSet *)UARTBASEADDR[ch];

	SOURCE_CLOCK = NX_CLKPWR_GetPLLFrequency(UARTSRC);

	GPIOSetAltFunction(GPIOALTNUM[ch * 2 + 0]);
	GPIOSetAltFunction(GPIOALTNUM[ch * 2 + 1]);

	pReg_Tieoff->TIEOFFREG[((UARTSMC[ch * 3 + 0]) & 0xFFFF) >> 5] &=
		(~(1 << ((UARTSMC[ch * 3 + 0]) & 0x1F)));
	pReg_Tieoff->TIEOFFREG[((UARTSMC[ch * 3 + 1]) & 0xFFFF) >> 5] &=
		(~(1 << ((UARTSMC[ch * 3 + 1]) & 0x1F)));
	pReg_Tieoff->TIEOFFREG[((UARTSMC[ch * 3 + 2]) & 0xFFFF) >> 5] &=
		(~(1 << ((UARTSMC[ch * 3 + 2]) & 0x1F)));

	ResetCon(RESETNUM[ch], CTRUE);		// reset on
	ResetCon(RESETNUM[ch], CFALSE);		// reset negate

	pReg_UartClkGen->clkenb =(1 << 3); 	// PCLKMODE : always, Clock Gen Disable
	pReg_UartClkGen->clkgen[0] =
		((SOURCE_DIVID - 1) << 5) | (UARTSRC << 2);

	pReg_Uart->LCR_H = 0x0070;	// 8 bit, none parity, stop 1, normal mode
	pReg_Uart->CR = 0x0300;		// rx, tx enable

	pReg_Uart->IBRD =
		(u16)((SOURCE_CLOCK / SOURCE_DIVID) /
				((BAUD_RATE / 1) * 16)); // IBRD = 8, 115200bps
	pReg_Uart->FBRD = (u16)((((((SOURCE_CLOCK / SOURCE_DIVID) %
					((BAUD_RATE / 1) * 16)) + 32) * 64) /
					((BAUD_RATE / 1) * 16))); // FBRD = 0,
	pReg_UartClkGen->clkenb =
		(1 << 3) | (1 << 2);	// PCLKMODE : always, Clock Gen Enable
	pReg_Uart->CR = 0x0301;		// rx, tx, uart enable

	return CTRUE;
}

void DebugPutch(s8 ch)
{
	const u16 TX_FIFO_FULL = 1 << 5;
	while (pReg_Uart->FR & TX_FIFO_FULL)
		;
	pReg_Uart->DR = (u32)ch;
}

cbool DebugIsUartTxDone(void)
{
	const u16 UART_TX_BUSY = 1 << 3;
	const u16 TX_FIFO_EMPTY = 1 << 7;
	return ((pReg_Uart->FR & (UART_TX_BUSY | TX_FIFO_EMPTY)) ==
			TX_FIFO_EMPTY ? CTRUE : CFALSE);
}
#if 0
cbool DebugIsTXEmpty(void)
{
	const u16 TX_FIFO_EMPTY = 1 << 7;
	return (cbool)(pReg_Uart->FR & TX_FIFO_EMPTY);
}

cbool DebugIsBusy(void)
{
	const u16 UART_TX_BUSY = 1 << 3;
	return (cbool)(pReg_Uart->FR & UART_TX_BUSY);
}

S8 DebugGetch(void)
{
	const u16 RX_FIFO_EMPTY = 1 << 4;
	while (pReg_Uart->FR & RX_FIFO_EMPTY)
		;
	return (S8)pReg_Uart->DR;
}
#endif

