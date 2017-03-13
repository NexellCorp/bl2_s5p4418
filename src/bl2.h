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
#ifndef __NX_SECONDBOOT_H__
#define __NX_SECONDBOOT_H__


#define HEADER_ID	((((u32)'N') <<  0) |	\
			 (((u32)'S') <<  8) |	\
			 (((u32)'I') << 16) |	\
			 (((u32)'H') << 24))


enum
{
	BOOT_FROM_USB   = 0UL,
	BOOT_FROM_SPI   = 1UL,
	BOOT_FROM_NAND  = 2UL,
	BOOT_FROM_SDMMC = 3UL,
	BOOT_FROM_SDFS  = 4UL,
	BOOT_FROM_UART  = 5UL
};

struct NX_NANDBootInfo
{
	u8  AddrStep;
	u8  tCOS;
	u8  tACC;
	u8  tOCH;
#if 0
	u32 PageSize    :24;    // 1 byte unit
	u32 LoadDevice  :8;
#else
	u8  PageSize;           // 512bytes unit
	u8  TIOffset;           // 3rd boot Image copy Offset. 1MB unit.
	u8  CopyCount;          // 3rd boot image copy count
	u8  LoadDevice;         // device chip select number
#endif
	u32 CRC32;
};

struct NX_SPIBootInfo
{
	u8  AddrStep;
	u8  _Reserved0[2];
	u8  PortNumber;

	u32 _Reserved1  : 24;
	u32 LoadDevice  : 8;

	u32 CRC32;
};

struct NX_UARTBootInfo
{
	u32 _Reserved0;

	u32 _Reserved1  : 24;
	u32 LoadDevice  : 8;

	u32 CRC32;
};

struct NX_SDMMCBootInfo
{
#if 1
	u8  PortNumber;
	u8  _Reserved0[3];
#else
	u8  _Reserved0[3];
	u8  PortNumber;
#endif

	u32 _Reserved1  : 24;
	u32 LoadDevice  : 8;

	u32 CRC32;
};

struct NX_DDR3DEV_DRVDSInfo
{
	u8  MR2_RTT_WR;
	u8  MR1_ODS;
	u8  MR1_RTT_Nom;
	u8  _Reserved0;
};

struct NX_LPDDR3DEV_DRVDSInfo
{
	u8  MR3_DS      : 4;
	u8  MR11_DQ_ODT : 2;
	u8  MR11_PD_CON : 1;
	u8  _Reserved0  : 1;

	u8  _Reserved1;
	u8  _Reserved2;
	u8  _Reserved3;
};

struct NX_DDRPHY_DRVDSInfo
{
	u8  DRVDS_Byte0;    // Data Slice 0
	u8  DRVDS_Byte1;    // Data Slice 1
	u8  DRVDS_Byte2;    // Data Slice 2
	u8  DRVDS_Byte3;    // Data Slice 3

	u8  DRVDS_CK;       // CK
	u8  DRVDS_CKE;      // CKE
	u8  DRVDS_CS;       // CS
	u8  DRVDS_CA;       // CA[9:0], RAS, CAS, WEN, ODT[1:0], RESET, BANK[2:0]

	u8  ZQ_DDS;         // zq mode driver strength selection.
	u8  ZQ_ODT;
	u8  _Reserved0[2];
};

struct NX_SDFSBootInfo
{
	char BootFileName[12];      // 8.3 format ex)"NXDATA.TBL"
};

union NX_DeviceBootInfo
{
	struct NX_NANDBootInfo  NANDBI;
	struct NX_SPIBootInfo   SPIBI;
	struct NX_SDMMCBootInfo SDMMCBI;
	struct NX_SDFSBootInfo  SDFSBI;
	struct NX_UARTBootInfo  UARTBI;
};

struct NX_DDRInitInfo
{
	u8  ChipNum;        // 0x88
	u8  ChipRow;        // 0x89
	u8  BusWidth;       // 0x8A
	u8  ChipCol;        // 0x8B

	u16 ChipMask;       // 0x8C
	u16 ChipBase;       // 0x8E

#if 0
	u8  CWL;            // 0x90
	u8  WL;             // 0x91
	u8  RL;             // 0x92
	u8  DDRRL;          // 0x93
#else
	u8  CWL;            // 0x90
	u8  CL;             // 0x91
	u8  MR1_AL;         // 0x92, MR2_RLWL (LPDDR3)
	u8  MR0_WR;         // 0x93, MR1_nWR (LPDDR3)
#endif

	u32 READDELAY;      // 0x94
	u32 WRITEDELAY;     // 0x98

	u32 TIMINGPZQ;      // 0x9C
	u32 TIMINGAREF;     // 0xA0
	u32 TIMINGROW;      // 0xA4
	u32 TIMINGDATA;     // 0xA8
	u32 TIMINGPOWER;    // 0xAC
};

struct NX_SecondBootInfo
{
	u32 VECTOR[8];                  // 0x000 ~ 0x01C
	u32 VECTOR_Rel[8];              // 0x020 ~ 0x03C

	u32 DEVICEADDR;                 // 0x040

	u32 LOADSIZE;                   // 0x044
	u32 LOADADDR;                   // 0x048
	u32 LAUNCHADDR;                 // 0x04C
	union NX_DeviceBootInfo DBI;    // 0x050~0x058

	u32 PLL[4];                     // 0x05C ~ 0x068
	u32 PLLSPREAD[2];               // 0x06C ~ 0x070

	u32 DVO[5];                     // 0x074 ~ 0x084

	struct NX_DDRInitInfo DII;      // 0x088 ~ 0x0AC

#if defined(MEM_TYPE_DDR3)
	struct NX_DDR3DEV_DRVDSInfo     DDR3_DSInfo;    // 0x0B0
#endif
#if defined(MEM_TYPE_LPDDR23)
	struct NX_LPDDR3DEV_DRVDSInfo   LPDDR3_DSInfo;  // 0x0B0
#endif
	struct NX_DDRPHY_DRVDSInfo      PHY_DSInfo;     // 0x0B4 ~ 0x0BC

	u16 LvlTr_Mode;                 // 0x0C0 ~ 0x0C1
	u16 FlyBy_Mode;                 // 0x0C2 ~ 0x0C3

	u32 Stub[(0x1EC-0x0C4)/4+1];      // 0x0C4 ~ 0x1EC

	u32 MemTestAddr;                // 0x1EC
	u32 MemTestSize;                // 0x1F0
	u32 MemTestTryCount;            // 0x1F4

	u32 BuildInfo;                  // 0x1F8

	u32 SIGNATURE;                  // 0x1FC    "NSIH"
} __attribute__ ((packed,aligned(4)));

// [0] : Use ICache
// [1] : Change PLL
// [2] : Decrypt
// [3] : Suspend Check

#endif //__NX_SECONDBOOT_H__
