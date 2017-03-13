/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 * 
 * NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 * AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 * FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Module	: SDMMC
 * File		: nx_sdmmc.h
 * Description	:
 * Author	: sei (parkjh@nexell.com)
 * History	:
 */

#ifndef __NX_SDMMC_H__
#define __NX_SDMMC_H__

#include "nx_prototype.h"

struct  NX_SDMMC_RegisterSet {
	u32	CTRL;			/* 0x000 : Control */
	u32	PWREN;			/* 0x004 : Power Enable */
	u32	CLKDIV;			/* 0x008 : Clock Divider */
	u32	CLKSRC;			/* 0x00C : Clock Source */
	u32	CLKENA;			/* 0x010 : Clock Enable */
	u32	TMOUT;			/* 0x014 : Time-Out */
	u32	CTYPE;			/* 0x018 : Card Type */
	u32	BLKSIZ;			/* 0x01C : Block Size */
	u32	BYTCNT;			/* 0x020 : Byte Count */
	u32	INTMASK;		/* 0x024 : Interrupt Mask */
	u32	CMDARG;			/* 0x028 : Command Argument */
	u32	CMD;			/* 0x02C : Command */
	u32	RESP0;			/* 0x030 : Response 0 */
	u32	RESP1;			/* 0x034 : Response 1 */
	u32	RESP2;			/* 0x038 : Response 2 */
	u32	RESP3;			/* 0x03C : Response 3 */
	u32	MINTSTS;		/* 0x040 : Masked Interrupt Status */
	u32	RINTSTS;		/* 0x044 : Raw Interrupt Status */
	u32	STATUS;			/* 0x048 : Status Register - Mainly for Debug Purpose      */
	u32	FIFOTH;			/* 0x04C : FIFO Threshold */
	u32	CDETECT;		/* 0x050 : Card Detect */
	u32	WRTPRT;			/* 0x054 : Write Protect */
	u32	GPIO;			/* 0x058 : General Purpose Input/Output */
	u32	TCBCNT;			/* 0x05C : Transferred CIU card byte count                 */
	u32	TBBCNT;			/* 0x060 : Transferred Host Byte Count                     */
	u32	DEBNCE;			/* 0x064 : Card Detect Debounce */
	u32	USRID;			/* 0x068 : User ID */
	u32	VERID;			/* 0x06C : Version ID */
	u32	HCON;			/* 0x070 : Hardware Configuration */
	u32	UHS_REG;		/* 0x074 : UHS_REG */
	u32	RSTn;			/* 0x078 : Hardware reset */
	u32	_R0;			/* 0x07C */
	u32	BMOD;			/* 0x080 : Bus Mode */
	u32	PLDMND;			/* 0x084 : Poll Demand */
	u32	DBADDR;			/* 0x088 : Descriptor List Base Address */
	u32	IDSTS;			/* 0x08C : Internal DMAC Status */
	u32	IDINTEN;		/* 0x090 : Internal DMAC Interrupt Enable */
	u32	DSCADDR;		/* 0x094 : Current Host Descriptor Address */
	u32	BUFADDR;		/* 0x098 : Current Buffer Descriptor Address */
	u8	_R1[0x100 - 0x09C];	/* 0x09C ~ 0x100 reserved area */
	u32	CARDTHRCTL;		/* 0x100 : Card Read Threshold Enable */
	u32	BACKEND_POWER;		/* 0x104 : Back-end Power */
	u32	UHS_REG_EXT;		/* 0x108 : eMMC 4.5 1.2V */
	u32	EMMC_DDR_REG;		/* 0x10C : eMMC DDR START bit detection control */
	u32	ENABLE_SHIFT;		/* 0x110 : Phase shift control */
	u32	CLKCTRL;		/* 0x114 : External clock phase & delay control */
	u8	_R2[0x200 - 0x118];	/* 0x118 ~ 0x200 */
	u32	DATA;			/* 0x200 : Data */
};

/// @brief  SDMMC BIU
struct strNxSdmmcBiu {
	u32    CTRL;
	u32    BSIZE;
	u32    BADDR;
	struct strNxSdmmcBiu *Next;
};

typedef struct strNxSdmmcBiu    NX_SDMMC_BIU;

/// @brief  SDMMC BIU Config
typedef struct {
	cbool   OWN;
	cbool   IntDisable;
	u32     BuffAddr;
	u32     DataSize;
} NX_SDMMC_BIUConfig;

/// @brief  SDMMC Interrupts for Interrupt Interface
enum    NX_SDMMC_INT {
	NX_SDMMC_INT_SDIO   = 16,   ///< SDIO Interrupt.\r\n
	///     Interrupt from SDIO card.
	NX_SDMMC_INT_EBE    = 15,   ///< End Bit Error for reading, Write no CRC for wrting.\r\n
	///     Error in end-bit during read operations, or no data CRC or negative CRC
	///     received during write operation.\r\n\r\n
	///     \b Note> \r\n
	///     For MMC CMD19, there may be no CRC status returned by the card.
	///     Hence, NX_SDMMC_INT_EBE is set for CMD19. The application should not treat
	///     this as an error.
	NX_SDMMC_INT_ACD    = 14,   ///< Auto Command Done.\r\n
	///     Stop/abort commands automatically sent by card unit and not initiated by
	///     host; similar to Command Done (NX_SDMMC_INT_CD) interrupt.
	NX_SDMMC_INT_SBE    = 13,   ///< Start Bit Error.\r\n
	///     Error in data start bit when data is read from a card. In 4-bit mode, if all
	///     data bits do not have start bit, then this error is set.
	NX_SDMMC_INT_HLE    = 12,   ///< Hardware Locked Write Error.\r\n
	///     This interrupt is genearted when the SDMMC module cannot load a command
	///     issued by the user. When the user sets a command with NX_SDMMC_CMDFLAG_STARTCMD
	///     flag, the SDMMC module tries to load the command. If the command buffer is
	///     already filled with a command, this error is raised.
	///     And also if the user try to modify any of settings while a command loading is in
	///     progress, then the modification is ignored and the SDMMC module generates this
	///     error.
	NX_SDMMC_INT_FRUN   = 11,   ///< FIFO underrun/overrun Error.\r\n
	///     Host tried to push data when FIFO was full, or host tried to read data
	///     when FIFO was empty. Typically this should not happen, except due to
	///     error in software.\r\n
	///     SDMMC module never pushes data into FIFO when FIFO is full, and pop data
	///     when FIFO is empty.
	NX_SDMMC_INT_HTO    = 10,   ///< Data Starvation by Host Timeout.\r\n
	///     To avoid data loss, SDCLK is stopped if FIFO is empty
	///     when writing to card, or FIFO is full when reading from card. Whenever
	///     SDCLK is stopped to avoid data loss, data-starvation timeout counter
	///     is started with data-timeout value. This interrupt is set if host does not fill
	///     data into FIFO during write to card, or does not read from FIFO during
	///     read from card before timeout period.\r\n
	///     Even after timeout, SDCLK stays in stopped state with SDMMC module waiting.
	///     It is responsibility of host to push or pop data into FIFO upon interrupt,
	///     which automatically restarts SDCLK and SDMMC module.\r\n
	///     Even if host wants to send stop/abort command, it still needs to ensure it
	///     has to push or pop FIFO so that clock starts in order for stop/abort
	///     command to send on cmd signal along with data that is sent or received
	///     on data line.
	NX_SDMMC_INT_DRTO   = 9,    ///< Data Read Timeout.\r\n
	///     Data timeout occurred. Data Transfer Over (NX_SDMMC_INT_DTO) also set if data
	///     timeout occurs.
	NX_SDMMC_INT_RTO    = 8,    ///< Response Timeout.\r\n
	///     Response timeout occurred. Command Done (NX_SDMMC_INT_CD) also set if response
	///     timeout occurs. If command involves data transfer and when response
	///     times out, no data transfer is attempted by SDMMC module.
	NX_SDMMC_INT_DCRC   = 7,    ///< Data CRC Error.\r\n
	///     Received Data CRC does not match with locally-generated CRC in SDMMC module.
	NX_SDMMC_INT_RCRC   = 6,    ///< Response CRC Error.\r\n
	///     Response CRC does not match with locally-generated CRC in SDMMC module.
	NX_SDMMC_INT_RXDR   = 5,    ///< Receive FIFO Data Request.\r\n
	///     Interrupt set during read operation from card when FIFO level is greater
	///     than Receive-Threshold level.\r\n\r\n
	///     \b Recommendation> In DMA modes, this interrupt should not be enabled.\r\n\r\n
	///     ISR, in non-DMA mode: \r\n
	/// @code
	/// pop RX_WMark + 1 data from FIFO
	/// @endcode
	NX_SDMMC_INT_TXDR   = 4,    ///< Transmit FIFO Data Request.\r\n
	///     Interrupt set during write operation to card when FIFO level reaches less
	///     than or equal to Transmit-Threshold level.\r\n\r\n
	///     \b Recommendation> In DMA modes, this interrupt should not be enabled.\r\n\r\n
	///     ISR in non-DMA mode: \r\n
	/// @code
	/// if (pending_bytes > (16 - TX_WMark))
	///     push (16 - TX_WMark) data into FIFO
	/// else
	///     push pending_bytes data into FIFO
	/// @endcode
	NX_SDMMC_INT_DTO    = 3,    ///< Data Transfer Over.\r\n
	///     Data transfer completed, even if there is Start Bit Error or CRC error.
	///     This bit is also set when "read data-timeout" occurs.\r\n\r\n
	///     \b Recommendation> \r\n
	///     In non-DMA mode, when data is read from card, on seeing interrupt,
	///     host should read any pending data from FIFO.\r\n
	///     In DMA mode, DMA controllers guarantee FIFO is flushed before interrupt.\r\n\r\n
	///     \b Note> \r\n
	///     NX_SDMMC_INT_DTO is set at the end of the last data block, even if
	///     the device asserts MMC busy after the last data block.
	NX_SDMMC_INT_CD     = 2,    ///< Command Done.\r\n
	///     Command sent to card and got response from card, even if Response
	///     Error or CRC error occurs. Also set when response timeout occurs.
	NX_SDMMC_INT_RE     = 1,    ///< Response Error.\r\n
	///     Error in received response set if one of following occurs:
	///     - Transmission bit != 0
	///     - Command index mismatch
	///     - End-bit != 1
	NX_SDMMC_INT_CDET   = 0     ///< Card Detected.
};

/// @brief  Command Flags for NX3_SDMMC_SetCommand()
enum    NX_SDMMC_CMDFLAG {
	NX_SDMMC_CMDFLAG_STARTCMD           = 1UL<<31,  ///< Start Command.
	///     Set a command with this flag to update modified settings to the
	///     SDMMC module. If this flag is set, you have not to modify any
	///     any settings until the command is taken by the SDMMC module.
	NX_SDMMC_CMDFLAG_USE_HOLD           = 1UL<<29,  ///< Use Hold Register
	///     0: CMD and DATA sent to card bypassing HOLD Register
	///     1: CMD and DATA sent to card through the HOLD Register
	NX_SDMMC_CMDFLAG_VOLT_SWITCH        = 1UL<<28,  ///< Volatage switch bit
	NX_SDMMC_CMDFLAG_BOOT_MODE          = 1UL<<27,  ///< boot mode
	NX_SDMMC_CMDFLAG_DISABLE_BOOT       = 1UL<<26,  ///< disable boot
	NX_SDMMC_CMDFLAG_EXPECT_BOOT_ACK    = 1UL<<25,  ///< expect boot ack
	NX_SDMMC_CMDFLAG_ENABLE_BOOT        = 1UL<<24,  ///< enable boot
	NX_SDMMC_CMDFLAG_CCS_EXPECTED       = 1UL<<23,  ///< ccs expected
	NX_SDMMC_CMDFLAG_READ_CEATA         = 1UL<<22,  ///< Read ceata
	NX_SDMMC_CMDFLAG_UPDATECLKONLY      = 1UL<<21,  ///< Just update clock settings for SDCLK into card clock domain.\r\n
	///     Changes card clocks (change frequency, truncate off or on, and
	///     set low-frequency mode); provided in order to change clock
	///     frequency or stop clock without having to send command to
	///     cards.\r\n
	///     Even though this flag is set with NX_SDMMC_CMDFLAG_STARTCMD flag,
	///     SDMMC module does not issue NX_SDMMC_INT_CD signal upon command completion.
	NX_SDMMC_CMDFLAG_CARD_NUMBER        = 1UL<<16,  ///< Card Number in use.
	NX_SDMMC_CMDFLAG_SENDINIT           = 1UL<<15,  ///< Send initialization sequence before sending this command.\r\n
	///     After power on, 80 clocks must be sent to card for initialization
	///     before sending any commands to card. This flag should be set while
	///     sending first command to card so that controller will initialize
	///     clocks before sending command to card.
	NX_SDMMC_CMDFLAG_STOPABORT          = 1UL<<14,  ///< Stop or abort command intended to stop current data transfer in progress.\r\n
	///     When open-ended or predefined data transfer is in progress, and
	///     host issues stop or abort command to stop data transfer, this flag should
	///     be set so that command/data state-machines of SDMMC module can return
	///     correctly to idle state.
	NX_SDMMC_CMDFLAG_WAITPRVDAT         = 1UL<<13,  ///< Wait for previous data transfer completion before sending command.\r\n
	///     Command without this flag typically used to query
	///     status of card during data transfer or to stop current data transfer.
	NX_SDMMC_CMDFLAG_SENDAUTOSTOP       = 1UL<<12,  ///< Send stop command at end of data transfer.\r\n
	///     When set, SDMMC module sends stop command to card at end of data transfer. \r\n
	///     * when this flag should be set, since some data
	///     transfers do not need explicit stop commands.\r\n
	///     * open-ended transfers that software should explicitly send to
	///     stop command.\r\n
	///     Additionally, when "resume" is sent to resume . suspended
	///     memory access of SD-Combo card . this falg should be set correctly if
	///     suspended data transfer needs send_auto_stop.\r\n
	///     Don't care if no data expected from card.
	NX_SDMMC_CMDFLAG_BLOCK              = 0UL<<11,  ///< Block data transfer command.\r\n Don't care if no data expected from card.
	NX_SDMMC_CMDFLAG_STREAM             = 1UL<<11,  ///< Stream data transfer command.\r\n Don't care if no data expected from card.
	NX_SDMMC_CMDFLAG_TXDATA             = 3UL<< 9,  ///< Write to card.\r\n Do not set this flag if no data expected from card.
	NX_SDMMC_CMDFLAG_RXDATA             = 1UL<< 9,  ///< Read form card.\r\n Do not set this flag if no data expected from card.
	NX_SDMMC_CMDFLAG_CHKRSPCRC          = 1UL<< 8,  ///< Check response CRC.\r\n
	///     Some of command responses do not return valid CRC bits.
	///     Software should disable CRC checks for those commands in
	///     order to disable CRC checking by SDMMC module.
	NX_SDMMC_CMDFLAG_SHORTRSP           = 1UL<< 6,  ///< Short response expected from card.\r\n Do not set this flag if no response is expected from card.
	NX_SDMMC_CMDFLAG_LONGRSP            = 3UL<< 6   ///< Long response expected from card.\r\n Do not set this flag if no response is expected from card.
};

/// @brief  Command FSM state for NX_SDMMC_GetCommandFSM().
typedef enum {
	NX_SDMMC_CMDFSM_IDLE            = 0,    ///< Idle.
	NX_SDMMC_CMDFSM_SENDINIT        = 1,    ///< Send init sequence.
	NX_SDMMC_CMDFSM_TXCMDSTART      = 2,    ///< Tx command start bit
	NX_SDMMC_CMDFSM_TXCMDTX         = 3,    ///< Tx command tx bit.
	NX_SDMMC_CMDFSM_TXCMDINDEXARG   = 4,    ///< Tx command index + arg.
	NX_SDMMC_CMDFSM_TXCMDCRC7       = 5,    ///< Tx command CRC7.
	NX_SDMMC_CMDFSM_TXCMDEND        = 6,    ///< Tx command end bit.
	NX_SDMMC_CMDFSM_RXRSPSTART      = 7,    ///< Rx response start bit.
	NX_SDMMC_CMDFSM_RXRSPIRQ        = 8,    ///< Rx response IRQ response.
	NX_SDMMC_CMDFSM_RXRSPTX         = 9,    ///< Rx response tx bit.
	NX_SDMMC_CMDFSM_TXRSPCMDIDX     = 10,   ///< Rx response command index.
	NX_SDMMC_CMDFSM_RXRSPDATA       = 11,   ///< Rx response data.
	NX_SDMMC_CMDFSM_RXRSPCRC7       = 12,   ///< Rx response CRC7.
	NX_SDMMC_CMDFSM_RXRSPEND        = 13,   ///< Rx response end bit.
	NX_SDMMC_CMDFSM_CMDWAITNCC      = 14,   ///< Command path wait NCC.
	NX_SDMMC_CMDFSM_WAIT            = 15    ///< Wait; Comamnd to Response turnaround.
} NX_SDMMC_CMDFSM;

/// @brief  SDMMC clock phase shift
typedef enum {
	NX_SDMMC_CLOCK_SHIFT_0          = 0,
	NX_SDMMC_CLOCK_SHIFT_90         = 1,
	NX_SDMMC_CLOCK_SHIFT_180        = 2,
	NX_SDMMC_CLOCK_SHIFT_270        = 3
} NX_SDMMC_CLKSHIFT;

typedef enum
{
	NX_SDMMC_CLOCK_SOURCE_0		= 0,
	NX_SDMMC_CLOCK_SOURCE_1		= 1,
	NX_SDMMC_CLOCK_SOURCE_2		= 2,
	NX_SDMMC_CLOCK_SOURCE_3		= 3,
} NX_SDMMC_CLOCK_SOURCE;


#endif  // __NX_SDMMC_H__

