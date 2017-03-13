/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Module	: UART
 * File		: nx_uart.h
 * Description	:
 * Author	: 
 * History	:
 */
#ifndef _NX_UART_H
#define _NX_UART_H

/*------------------------------------------------------------------------------
//  includes
//----------------------------------------------------------------------------*/
#include "nx_prototype.h"


#define NX_UART_FIFO_DEPTH		32


/******************************************************************************/
/******************** REGISTER BIT MASKS **************************************/
/******************************************************************************/

/* For RSTMODE_REG Register */
#define RSTMODE_ENABLE      0x01
#define PCLK_ENABLE         0x02
#define PCLKGEN             0x03
#define REFCLKGEN           0x04
#define REFCLKON            0x05
#define PCLKON              0x06

/* For UTIIR Register */
#define UT_MSINT            0x01
#define UT_RXINT            0x02
#define UT_TXINT            0x04
#define UT_RTISINT          0x08
#define UT_UARTINTR         0x10
#define UT_UARTEINTR        0x20

/* For UT_FORCED_ERROR Register */
#define FORCED_PARITY_ERR   0x01
#define FORCED_FRAMING_ERR  0x02
#define RX_JITTER_BITS      0x0c
#define RX_JITTER_SIGN      0x10
#define TX_JITTER_BITS      0x60
#define TX_JITTER_SIGN      0x80

/* For UTFR Register */
#define UTRXFIFO_EMPTY      0x01
#define UTRXFIFO_HALFFULL   0x02
#define UTRXFIFO_FULL       0x04
#define UTTXFIFO_EMPTY      0x08
#define UTTXFIFO_HALFEMPTY  0x10
#define UTTXFIFO_FULL       0x20
#define UTTXBUSY            0x40
#define UTRXBUSY            0x80

/* For UTRSR Register */
#define UTPE                0x02

/* For UTDMACR Register */
#define TXDMASREQ           0x04
#define RXDMASREQ           0x08
#define TXDMABREQ           0x10
#define RXDMABREQ           0x20

/* For UARTFR Register */
#define UART_CTS            0x01
#define UART_DSR            0x02
#define UART_DCD            0x04
#define UART_UBUSY          0x08
#define UART_RXFE           0x10
#define UART_TXFF           0x20
#define UART_RXFF           0x40
#define UART_TXFE           0x80
#define UART_RI             0x100

/* For UARTIFLS Register */
#define UART_RXFEIGHT       0x00
#define UART_RXFQUART       0x08
#define UART_RXFHALF        0x10
#define UART_RXF3QUART      0x18
#define UART_RXF7EIGHT      0x20
#define UART_TXFEIGHT       0x00
#define UART_TXFQUART       0x01
#define UART_TXFHALF        0x02
#define UART_TXF3QUART      0x03
#define UART_TXF7EIGHT      0x04

/* UARTRIS Register */
#define UART_RIRINT         0x01
#define UART_CTSRINT        0x02
#define UART_DCDRINT        0x04
#define UART_DSRRINT        0x08
#define UART_RXRINT         0x10
#define UART_TXRINT         0x20
#define UART_RTRINT         0x40
#define UART_FERINT         0x80
#define UART_PERINT         0x100
#define UART_BERINT         0x200
#define UART_OERINT         0x400

/* UARTMIS Register */
#define UART_RIMINT         0x01
#define UART_CTSMINT        0x02
#define UART_DCDMINT        0x04
#define UART_DSRMINT        0x08
#define UART_RXMINT         0x10
#define UART_TXMINT         0x20
#define UART_RTMINT         0x40
#define UART_FEMINT         0x80
#define UART_PEMINT         0x100
#define UART_BEMINT         0x200
#define UART_OEMINT         0x400

/* UARTDMACR Register */
#define UART_RXDMAE         0x01
#define UART_TXDMAE         0x02
#define DMAONERR            0x04

struct NX_UART_RegisterSet {
	u32 DR;				/* 0x00	// Data Register */
	u32 RSR_ECR;			/* 0x04	// Receive Status Register / Error Clear Register */
	u32 __R0[(0x18-0x08)/4];	/* 0x08~0x14	// Reserved */
	u32 FR;				/* 0x18	// Flag Register */
	u32 __R1;			/* 0x1C	// Reserved */
	u32 ILPR;			/* 0x20	// IrDA Low Power Counter Register */
	u32 IBRD;			/* 0x24	// IntegerBaud Rate Register */
	u32 FBRD;			/* 0x28 // Fractional Baud Rate Register */
	u32 LCR_H;			/* 0x2C // Line Control Register */
	u32 CR;				/* 0x30 // Control Register */
	u32 IFLS;			/* 0x34	// Interrupt FIFO Level Select Register */
	u32 IMSC;			/* 0x38	// Interrupt Mask Set/Clear Register */
	u32 RIS;			/* 0x3C // Raw Interrupt Status Register */
	u32 MIS;			/* 0x40	// Masked Interrupt Status Register */
	u32 ICR;			/* 0x44	// Interrupt Clear Register */
	u32 DMACR;			/* 0x48	// DMA Control Register */
	u32 __R2[(0x80-0x4C)/4];	/* 0x4C~0x7C	// Reserved */
	u32 TCR;			/* 0x80 // Test Control Register */
	u32 ITIP;			/* 0x84 // Integration Test Input Register */
	u32 ITOP;			/* 0x88 // Integration Test Output Register */
	u32 TDR;			/* 0x8C // Test Data Register */
	u32 __R4[(0xFD0-0x90)/4];	/* 0x90~0xFCC	// Reserved */
	u32 __R5[(0xFE0-0xFD0)/4];	/* 0xFD0~0xFDC	// Reserved */
	u32 PeriphID0;			/* 0xFE0	// PeriphID0 Register */
	u32 PeriphID1;			/* 0xFE4	// PeriphID1 Register */
	u32 PeriphID2;			/* 0xFE8	// PeriphID2 Register */
	u32 PeriphID3;			/* 0xFEC	// PeriphID3 Register */
	u32 PCellID0;			/* 0xFF0	// PCellID0 Register */
	u32 PCellID1;			/* 0xFF4	// PCellID1 Register */
	u32 PCellID2;			/* 0xFF8	// PCellID2 Register */
	u32 PCellID3;			/* 0xFFC	// PCellID3 Register */
};


enum {
	NX_UART_INT_RIM		= 0UL,	/* RI Modem */
	NX_UART_INT_CTSM	= 1UL,	/* CTS Modem */
	NX_UART_INT_DCDM	= 2UL,	/* DCD Modem */
	NX_UART_INT_DSRM	= 3UL,	/* DSR Modem */
	NX_UART_INT_RX		= 4UL,	/* Receive */
	NX_UART_INT_TX		= 5UL,	/* Transmit */
	NX_UART_INT_RT		= 6UL,	/* Receive Timeout */
	NX_UART_INT_FE		= 7UL,	/* Framing Error */
	NX_UART_INT_PE		= 8UL,	/* Parity Error */
	NX_UART_INT_BE		= 9UL,	/* Break Error */
	NX_UART_INT_OE		= 10UL	/* Overrun Error */
};

enum {
	NX_UART_CR_UARTEN	= 0UL,
	NX_UART_CR_SIREN	= 1UL,
	NX_UART_CR_IIRLP	= 2UL,
	NX_UART_CR_LPE		= 7UL,
	NX_UART_CR_TXE		= 8UL,
	NX_UART_CR_RXE		= 9UL,
	NX_UART_CR_DTR		= 10UL,
	NX_UART_CR_RTS		= 11UL,
	NX_UART_CR_OUT1		= 12UL,
	NX_UART_CR_OUT2		= 13UL,
	NX_UART_CR_RTSEN	= 14UL,
	NX_UART_CR_CTSEN	= 15UL
};

typedef enum {
	NX_UART_PARITYMODE_NONE	= 0UL,	/* No */
	NX_UART_PARITYMODE_ODD	= 1UL,	/* Odd */
	NX_UART_PARITYMODE_EVEN	= 2UL,	/* Even */
	NX_UART_PARITYMODE_FONE	= 3UL,	/* Force 1 */
	NX_UART_PARITYMODE_FZ	= 4UL	/* Force 0 */
}	NX_UART_PARITYMODE;

typedef enum {
	NX_UART_ERRSTAT_FRAME	= 1UL << 0,	/* Frame Error */
	NX_UART_ERRSTAT_PARITY	= 1UL << 1,	/* Parity Error */
	NX_UART_ERRSTAT_BREAK	= 1UL << 2,	/* Break Signal receive */
	NX_UART_ERRSTAT_OVERRUN	= 1UL << 3	/* Overrun Error */

}	NX_UART_ERRSTAT ;

typedef enum {
	NX_UART_FLAG_CTS	= 1UL << 0,	/* Clear to send */
	NX_UART_FLAG_DSR	= 1UL << 1,	/* Data set ready */
	NX_UART_FLAG_DCD	= 1UL << 2,	/* Data carrier detect */
	NX_UART_FLAG_BUSY	= 1UL << 3,	/* UART Busy */
	NX_UART_FLAG_RXFE	= 1UL << 4,	/* Receive FIFO empty */
	NX_UART_FLAG_TXFF	= 1UL << 5,	/* Transmit FIFO full */
	NX_UART_FLAG_RXFF	= 1UL << 6,	/* Receive FIFO full */
	NX_UART_FLAG_TXFE	= 1UL << 7,	/* Transmit FIFO empty */
	NX_UART_FLAG_RI		= 1UL << 8	/* Ring indicator */
}	NX_UART_FLAG;

typedef enum {
	NX_UART_RXDMAE			= 1UL << 0,	/* Clear to send */
	NX_UART_TXDMAE			= 1UL << 1,	/* Clear to send */
	NX_UART_DMAONERR		= 1UL << 2,	/* Clear to send */
}	NX_UART_DMA;

typedef enum {
	NX_UART_FIFOLEVEL1_8	= (NX_UART_FIFO_DEPTH * 1 / 8),	/* 1/8n */
	NX_UART_FIFOLEVEL2_8	= (NX_UART_FIFO_DEPTH * 2 / 8),	/* 1/4n */
	NX_UART_FIFOLEVEL4_8	= (NX_UART_FIFO_DEPTH * 4 / 8),	/* 1/2n */
	NX_UART_FIFOLEVEL6_8	= (NX_UART_FIFO_DEPTH * 6 / 8),	/* 3/4n */
	NX_UART_FIFOLEVEL7_8	= (NX_UART_FIFO_DEPTH * 7 / 8),	/* 7/8n */
	NX_UART_FIFOLEVEL_ERR	= 0xFFFFFFFFUL
}	NX_UART_FIFOLEVEL;

typedef enum {
	NX_UART_DATABIT_5	= 0UL,	/* 5 bits */
	NX_UART_DATABIT_6	= 1UL,	/* 6 bits */
	NX_UART_DATABIT_7	= 2UL,	/* 7 bits */
	NX_UART_DATABIT_8	= 4UL,	/* 8 bits */
	NX_UART_DATABIT_ERR	= 0xFFFFFFFFUL
}	NX_UART_DATABIT;


#endif // _NX_UART_H
