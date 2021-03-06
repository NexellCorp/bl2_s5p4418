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

#include "iUSBBOOT.h"
#include "nx_ecid.h"
#include <bl2.h>
#include <nx_bootheader.h>

#ifdef DEBUG
#define dprintf(x, ...) printf(x, ...)
#else
#define dprintf(x, ...)
#endif

void ResetCon(u32 devicenum, cbool en);

static volatile struct NX_USB_OTG_RegisterSet *const pUOReg =
	(struct NX_USB_OTG_RegisterSet *)PHY_BASEADDR_USB20OTG_MODULE_AHBS0;

volatile struct NX_ECID_RegisterSet *const pReg_ECID =
	(struct NX_ECID_RegisterSet *const)PHY_BASEADDR_ECID_MODULE;

static u8 __attribute__((aligned(4)))
	gs_DeviceDescriptorFS[DEVICE_DESCRIPTOR_SIZE] =
{
	18,                             //  0 desc size
	(u8)(DESCRIPTORTYPE_DEVICE),    //  1 desc type (DEVICE)
	(u8)(FULL_USB_VER % 0x100),     //  2 USB release
	(u8)(FULL_USB_VER / 0x100),     //  3 => 1.00
	0xFF,                           //  4 class
	0xFF,                           //  5 subclass
	0xFF,                           //  6 protocol
	(u8)FULL_MAX_PKT_SIZE_EP0,      //  7 max pack size
	(u8)(VENDORID % 0x100),         //  8 vendor ID LSB
	(u8)(VENDORID / 0x100),         //  9 vendor ID MSB
	(u8)(PRODUCTID % 0x100),        // 10 product ID LSB    (second product)
	(u8)(PRODUCTID / 0x100),        // 11 product ID MSB
	0x00,                           // 12 device release LSB
	0x00,                           // 13 device release MSB
	0x00,                           // 14 manufacturer string desc index
	0x00,                           // 15 product string desc index
	0x00,                           // 16 serial num string desc index
	0x01                            // 17 num of possible configurations
};

static u8 __attribute__((aligned(4)))
	gs_DeviceDescriptorHS[DEVICE_DESCRIPTOR_SIZE] =
{
	18,                             //  0 desc size
	(u8)(DESCRIPTORTYPE_DEVICE),    //  1 desc type (DEVICE)
	(u8)(HIGH_USB_VER % 0x100),     //  2 USB release
	(u8)(HIGH_USB_VER / 0x100),     //  3 => 1.00
	0xFF,                           //  4 class
	0xFF,                           //  5 subclass
	0xFF,                           //  6 protocol
	(u8)HIGH_MAX_PKT_SIZE_EP0,      //  7 max pack size
	(u8)(VENDORID    % 0x100),      //  8 vendor ID LSB
	(u8)(VENDORID    / 0x100),      //  9 vendor ID MSB
	(u8)(PRODUCTID % 0x100),        // 10 product ID LSB    (second product)
	(u8)(PRODUCTID / 0x100),        // 11 product ID MSB
	0x00,                           // 12 device release LSB
	0x00,                           // 13 device release MSB
	0x00,                           // 14 manufacturer string desc index
	0x00,                           // 15 product string desc index
	0x00,                           // 16 serial num string desc index
	0x01                            // 17 num of possible configurations
};


static const u8 __attribute__((aligned(4)))
	gs_ConfigDescriptorFS[CONFIG_DESCRIPTOR_SIZE] =
{
	//--------------------------------------------------------------------------
	// Configuration Descriptor
	0x09,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_CONFIGURATION),         // [ 1] desc type (CONFIGURATION)
	(u8)(CONFIG_DESCRIPTOR_SIZE % 0x100),       // [ 2] total length of data returned LSB
	(u8)(CONFIG_DESCRIPTOR_SIZE / 0x100),       // [ 3] total length of data returned MSB
	0x01,                                       // [ 4] num of interfaces
	0x01,                                       // [ 5] value to select config (1 for now)
	0x00,                                       // [ 6] index of string desc ( 0 for now)
	CONF_ATTR_DEFAULT | CONF_ATTR_SELFPOWERED,  // [ 7] bus powered
	25,                                         // [ 8] max power, 50mA for now

	//--------------------------------------------------------------------------
	// Interface Decriptor
	0x09,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_INTERFACE),             // [ 1] desc type (INTERFACE)
	0x00,                                       // [ 2] interface index.
	0x00,                                       // [ 3] value for alternate setting
	0x02,                                       // [ 4] bNumEndpoints (number endpoints used, excluding EP0)
	0xFF,                                       // [ 5]
	0xFF,                                       // [ 6]
	0xFF,                                       // [ 7]
	0x00,                                       // [ 8] string index,

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 1 Bulk IN)
	0x07,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_ENDPOINT),              // [ 1] desc type (ENDPOINT)
	BULK_IN_EP|EP_ADDR_IN,                      // [ 2] endpoint address: endpoint 1, IN
	EP_ATTR_BULK,                               // [ 3] endpoint attributes: Bulk
	(u8)(FULL_MAX_PKT_SIZE_EP1 % 0x100),        // [ 4] max packet size LSB
	(u8)(FULL_MAX_PKT_SIZE_EP1 / 0x100),        // [ 5] max packet size MSB
	0x00,                                       // [ 6] polling interval (4ms/bit=time,500ms)

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 2 Bulk OUT)
	0x07,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_ENDPOINT),              // [ 1] desc type (ENDPOINT)
	BULK_OUT_EP | EP_ADDR_OUT,                  // [ 2] endpoint address: endpoint 2, OUT
	EP_ATTR_BULK,                               // [ 3] endpoint attributes: Bulk
	(u8)(FULL_MAX_PKT_SIZE_EP2 % 0x100),        // [ 4] max packet size LSB
	(u8)(FULL_MAX_PKT_SIZE_EP2 / 0x100),        // [ 5] max packet size MSB
	0x00                                        // [ 6] polling interval (4ms/bit=time,500ms)
};

static const u8 __attribute__((aligned(4)))
	gs_ConfigDescriptorHS[CONFIG_DESCRIPTOR_SIZE] =
{
	//--------------------------------------------------------------------------
	// Configuration Descriptor
	0x09,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_CONFIGURATION),         // [ 1] desc type (CONFIGURATION)
	(u8)(CONFIG_DESCRIPTOR_SIZE % 0x100),       // [ 2] total length of data returned LSB
	(u8)(CONFIG_DESCRIPTOR_SIZE / 0x100),       // [ 3] total length of data returned MSB
	0x01,                                       // [ 4] num of interfaces
	0x01,                                       // [ 5] value to select config (1 for now)
	0x00,                                       // [ 6] index of string desc ( 0 for now)
	CONF_ATTR_DEFAULT | CONF_ATTR_SELFPOWERED,  // [ 7] bus powered
	25,                                         // [ 8] max power, 50mA for now

	//--------------------------------------------------------------------------
	// Interface Decriptor
	0x09,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_INTERFACE),             // [ 1] desc type (INTERFACE)
	0x00,                                       // [ 2] interface index.
	0x00,                                       // [ 3] value for alternate setting
	0x02,                                       // [ 4] bNumEndpoints (number endpoints used, excluding EP0)
	0xFF,                                       // [ 5]
	0xFF,                                       // [ 6]
	0xFF,                                       // [ 7]
	0x00,                                       // [ 8] string index,

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 1 Bulk IN)
	0x07,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_ENDPOINT),              // [ 1] desc type (ENDPOINT)
	BULK_IN_EP | EP_ADDR_IN,                    // [ 2] endpoint address: endpoint 1, IN
	EP_ATTR_BULK,                               // [ 3] endpoint attributes: Bulk
	(u8)(HIGH_MAX_PKT_SIZE_EP1 % 0x100),        // [ 4] max packet size LSB
	(u8)(HIGH_MAX_PKT_SIZE_EP1 / 0x100),        // [ 5] max packet size MSB
	0x00,                                       // [ 6] polling interval (4ms/bit=time,500ms)

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 2 Bulk OUT)
	0x07,                                       // [ 0] desc size
	(u8)(DESCRIPTORTYPE_ENDPOINT),              // [ 1] desc type (ENDPOINT)
	BULK_OUT_EP|EP_ADDR_OUT,                    // [ 2] endpoint address: endpoint 2, OUT
	EP_ATTR_BULK,                               // [ 3] endpoint attributes: Bulk
	(u8)(HIGH_MAX_PKT_SIZE_EP2 % 0x100),        // [ 4] max packet size LSB
	(u8)(HIGH_MAX_PKT_SIZE_EP2 / 0x100),        // [ 5] max packet size MSB
	0x00                                        // [ 6] polling interval (4ms/bit=time,500ms)
};

static void nx_usb_write_in_fifo(u32 ep, u8 *buf, s32 num)
{
	s32 i;
	u32 *dwbuf = (u32 *)buf; /* assume all data ptr is 4 bytes aligned */
	for (i = 0; i < (num + 3) / 4; i++)
		pUOReg->EPFifo[ep][0] = dwbuf[i];
}

/*
 * CRC Check for modifications.
 * A global variable for a CRC check.
 * */
static struct NX_SecondBootInfo *g_TBI;
static USBBOOTSTATUS *g_USBBootStatus;

static void nx_usb_read_out_fifo(u32 ep, u8 *buf, s32 num)
{
	s32 i;
	u32 *dwbuf = (u32 *)buf;

	for (i = 0; i < (num + 3) / 4; i++) {
		dwbuf[i] = pUOReg->EPFifo[ep][0];
	}
}

static void nx_usb_ep0_int_hndlr(USBBOOTSTATUS *pUSBBootStatus)
{
	u32 buf[2];
	SetupPacket *pSetupPacket = (SetupPacket *)buf;
	u16 addr;

	dprintf("Event EP0\r\n");

	if (pUSBBootStatus->ep0_state != EP0_STATE_INIT)
	       goto noep0;

	buf[0] = pUOReg->EPFifo[CONTROL_EP][0];
	buf[1] = pUOReg->EPFifo[CONTROL_EP][0];

	dprintf("Req:%02X %02X %04X %04X %04X\r\n",
			pSetupPacket->bmRequestType,
			pSetupPacket->bRequest,
			pSetupPacket->wValue,
			pSetupPacket->wIndex,
			pSetupPacket->wLength);
	switch (pSetupPacket->bRequest) {
	case STANDARD_SET_ADDRESS:
		/* Set Address Update bit */
		addr = (pSetupPacket->wValue & 0xFF);
		dprintf("STANDARD_SET_ADDRESS: %02X\r\n", addr);
		pUOReg->DCSR.DCFG =
			1 << 18 | addr << 4 |
			pUSBBootStatus->speed << 0;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_SET_DESCRIPTOR:
		dprintf("STANDARD_SET_DESCRIPTOR\r\n");
		break;

	case STANDARD_SET_CONFIGURATION:
		dprintf("STANDARD_SET_CONFIGURATION\r\n");
		/* Configuration value in configuration descriptor */
		pUSBBootStatus->CurConfig = pSetupPacket->wValue;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_GET_CONFIGURATION:
		dprintf("STANDARD_GET_CONFIGURATION\r\n");
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) |
							(1 << 0);
		/*ep0 enable, clear nak, next ep0, 8byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			EPEN_CNAK_EP0_8;
		pUOReg->EPFifo[CONTROL_EP][0] =
			pUSBBootStatus->CurConfig;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_GET_DESCRIPTOR:
		dprintf("STANDARD_GET_DESCRIPTOR :");
		pUSBBootStatus->Remain_size =
			(u32)pSetupPacket->wLength;
		switch (pSetupPacket->wValue >> 8) {
		case DESCRIPTORTYPE_DEVICE:
			pUSBBootStatus->Current_ptr =
				(u8*)pUSBBootStatus->DeviceDescriptor;
			pUSBBootStatus->Current_Fifo_Size =
				pUSBBootStatus->ctrl_max_pktsize;
			if (pUSBBootStatus->Remain_size >
					DEVICE_DESCRIPTOR_SIZE)
				pUSBBootStatus->Remain_size =
					DEVICE_DESCRIPTOR_SIZE;
			pUSBBootStatus->ep0_state = EP0_STATE_GET_DSCPT;
			break;

		case DESCRIPTORTYPE_CONFIGURATION:
			pUSBBootStatus->Current_ptr =
				(u8*)pUSBBootStatus->ConfigDescriptor;
			pUSBBootStatus->Current_Fifo_Size =
				pUSBBootStatus->ctrl_max_pktsize;
			if (pUSBBootStatus->Remain_size >
					CONFIG_DESCRIPTOR_SIZE)
				pUSBBootStatus->Remain_size =
					CONFIG_DESCRIPTOR_SIZE;
			pUSBBootStatus->ep0_state = EP0_STATE_GET_DSCPT;
			break;

			//            case DESCRIPTORTYPE_STRING :
			//            case DESCRIPTORTYPE_INTERFACE:
			//            case DESCRIPTORTYPE_ENDPOINT:
		default:
			pUOReg->DCSR.DEPIR[0].DIEPCTL |= DEPCTL_STALL;
			break;
		}
		break;

	case STANDARD_CLEAR_FEATURE:
		dprintf("STANDARD_CLEAR_FEATURE :");
		break;

	case STANDARD_SET_FEATURE:
		dprintf("STANDARD_SET_FEATURE :");
		break;

	case STANDARD_GET_STATUS:
		dprintf("STANDARD_GET_STATUS :");
		pUSBBootStatus->ep0_state = EP0_STATE_GET_STATUS;
		break;

	case STANDARD_GET_INTERFACE:
		dprintf("STANDARD_GET_INTERFACE\r\n");
		pUSBBootStatus->ep0_state = EP0_STATE_GET_INTERFACE;
		break;

	case STANDARD_SET_INTERFACE:
		dprintf("STANDARD_SET_INTERFACE\r\n");
		pUSBBootStatus->CurInterface = pSetupPacket->wValue;
		pUSBBootStatus->CurSetting = pSetupPacket->wValue;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_SYNCH_FRAME:
		dprintf("STANDARD_SYNCH_FRAME\r\n");
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	default:
		break;
	}
noep0:

	pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ =
		(1 << 19) | (pUSBBootStatus->ctrl_max_pktsize << 0);

	if(pUSBBootStatus->speed == USB_HIGH) {
		/*clear nak, next ep0, 64byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			((1 << 26) | (CONTROL_EP << 11) | (0 << 0));
	} else {
		/*clear nak, next ep0, 8byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			((1 << 26) | (CONTROL_EP << 11) | (3 << 0));
	}
}

static void nx_usb_transfer_ep0(USBBOOTSTATUS *pUSBBootStatus)
{
	switch (pUSBBootStatus->ep0_state) {
	case EP0_STATE_INIT:
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ =
			(1 << 19) | (0 << 0);
		/*ep0 enable, clear nak, next ep0, 8byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL = EPEN_CNAK_EP0_8;
		dprintf("EP0_STATE_INIT\r\n");
		break;

		/* GET_DESCRIPTOR:DEVICE */
	case EP0_STATE_GET_DSCPT:
		dprintf("EP0_STATE_GD_DEV_0 :");
		if (pUSBBootStatus->speed == USB_HIGH) {
			/*ep0 enable, clear nak, next ep0, max 64byte */
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
				EPEN_CNAK_EP0_64;
		} else {
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
				EPEN_CNAK_EP0_8;
		}
		if (pUSBBootStatus->Current_Fifo_Size >=
				pUSBBootStatus->Remain_size) {
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ =
				(1 << 19) | (pUSBBootStatus->Remain_size << 0);
			nx_usb_write_in_fifo(CONTROL_EP,
					pUSBBootStatus->Current_ptr,
					pUSBBootStatus->Remain_size);
			pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		} else {
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ =
				(1 << 19) |
				(pUSBBootStatus->Current_Fifo_Size << 0);
			nx_usb_write_in_fifo(CONTROL_EP,
					pUSBBootStatus->Current_ptr,
					pUSBBootStatus->Current_Fifo_Size);
			pUSBBootStatus->Remain_size -=
				pUSBBootStatus->Current_Fifo_Size;
			pUSBBootStatus->Current_ptr +=
				pUSBBootStatus->Current_Fifo_Size;
		}
		break;

	case EP0_STATE_GET_INTERFACE:
	case EP0_STATE_GET_CONFIG:
	case EP0_STATE_GET_STATUS:
		dprintf("EP0_STATE_INTERFACE_GET\r\n");
		dprintf("EP0_STATE_GET_STATUS\r\n");

		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) | (1 << 0);
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL = EPEN_CNAK_EP0_8;

		if(pUSBBootStatus->ep0_state == EP0_STATE_GET_INTERFACE)
			pUOReg->EPFifo[CONTROL_EP][0] =
				pUSBBootStatus->CurInterface;
		else if(pUSBBootStatus->ep0_state == EP0_STATE_GET_CONFIG)
			pUOReg->EPFifo[CONTROL_EP][0] =
				pUSBBootStatus->CurConfig;
		else
			pUOReg->EPFifo[CONTROL_EP][0] = 0;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	default:
		break;
	}
}

static void nx_usb_int_bulkin(USBBOOTSTATUS *pUSBBootStatus)
{
	u8 *bulkin_buf;
	u32 remain_cnt;

	dprintf("Bulk In Function\r\n");

	bulkin_buf = (u8*)pUSBBootStatus->up_ptr;
	remain_cnt = pUSBBootStatus->up_size -
			((u32)pUSBBootStatus->up_ptr -
			 pUSBBootStatus->up_addr);

	if (remain_cnt > pUSBBootStatus->bulkin_max_pktsize) {
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPTSIZ =
			(1 << 19) | (pUSBBootStatus->bulkin_max_pktsize << 0);

		/*ep1 enable, clear nak, bulk, usb active, next ep2, max pkt 64*/
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
			1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
			pUSBBootStatus->bulkin_max_pktsize << 0;

		nx_usb_write_in_fifo(BULK_IN_EP, bulkin_buf,
				pUSBBootStatus->bulkin_max_pktsize);

		pUSBBootStatus->up_ptr += pUSBBootStatus->bulkin_max_pktsize;

	} else if (remain_cnt > 0) {
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPTSIZ =
			(1 << 19) | (remain_cnt << 0);

		/*ep1 enable, clear nak, bulk, usb active, next ep2, max pkt 64*/
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
			1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
			pUSBBootStatus->bulkin_max_pktsize << 0;

		nx_usb_write_in_fifo(BULK_IN_EP, bulkin_buf, remain_cnt);

		pUSBBootStatus->up_ptr += remain_cnt;

	} else { /*remain_cnt = 0*/
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
			(DEPCTL_SNAK|DEPCTL_BULK_TYPE);
	}
}

static void nx_usb_int_bulkout(USBBOOTSTATUS * pUSBBootStatus,
		struct NX_SecondBootInfo * pTBI,
		u32 fifo_cnt_byte)
{
	u32 *pdwBuffer;

	if (CTRUE != pUSBBootStatus->bHeaderReceived) {
		pdwBuffer = (u32 *)pTBI;
		nx_usb_read_out_fifo(BULK_OUT_EP,
			(u8 *)&pdwBuffer[pUSBBootStatus->iRxHeaderSize / 4],
			fifo_cnt_byte);

		if ((fifo_cnt_byte & 3) == 0) {
			pUSBBootStatus->iRxHeaderSize += fifo_cnt_byte;
		} else {
			printf("ERROR : Header Packet Size must be 32-bit aligned.\r\n");
			pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL |= DEPCTL_STALL;
		}

		if (512 <= pUSBBootStatus->iRxHeaderSize) {
			if (pTBI->SIGNATURE == HEADER_ID) {	// "NSIH"
				pUSBBootStatus->bHeaderReceived = CTRUE;
				pUSBBootStatus->RxBuffAddr = (u8*)pTBI->LOADADDR;
				pUSBBootStatus->iRxSize = pTBI->LOADSIZE;
				printf("USB Load Address = 0x%08X "
					"Launch Address = 0x%08X, "
					"size = %d bytes\r\n",
						(s32)pUSBBootStatus->RxBuffAddr,
						pTBI->LAUNCHADDR,
						pUSBBootStatus->iRxSize);
			} else {
				printf("no header sig:%08X\r\n",
							pTBI->SIGNATURE);
				pUSBBootStatus->iRxHeaderSize = 0;
				pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL |=
					DEPCTL_STALL;
			}
		}
	} else {
		NX_ASSERT((pUSBBootStatus->iRxSize) > 0);
		NX_ASSERT(0 == ((u32)pUSBBootStatus->RxBuffAddr & 3));
		nx_usb_read_out_fifo(BULK_OUT_EP,
				(u8 *)pUSBBootStatus->RxBuffAddr,
				fifo_cnt_byte);

#if (0)
		dprintf("Bin Packet Size = %d => 0x%08X, %d\r\n", iRxSize,
				pUSBBootStatus->RxBuffAddr,
				pUSBBootStatus->iRxSize);
#endif

		pUSBBootStatus->RxBuffAddr += fifo_cnt_byte;
		pUSBBootStatus->iRxSize -= fifo_cnt_byte;

		if (pUSBBootStatus->iRxSize <= 0) {
			printf("Download completed!\r\n");

			pUSBBootStatus->bDownLoading = CFALSE;
			pUSBBootStatus->bHeaderReceived = CFALSE;
		}
	}

	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPTSIZ =
		(1 << 19) | (pUSBBootStatus->bulkout_max_pktsize << 0);

	/*ep2 enable, clear nak, bulk, usb active, next ep2, max pkt 64*/
	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL =
		1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
		pUSBBootStatus->bulkout_max_pktsize << 0;
}

static void nx_usb_reset(USBBOOTSTATUS *pUSBBootStatus)
{
	u32 i;
	/* set all out ep nak */
	for (i = 0; i < 16; i++)
		pUOReg->DCSR.DEPOR[i].DOEPCTL |= DEPCTL_SNAK;

	pUSBBootStatus->ep0_state = EP0_STATE_INIT;
	pUOReg->DCSR.DAINTMSK = ((1 << BULK_OUT_EP) | (1<< CONTROL_EP)) << 16 |
				((1 << BULK_IN_EP) | (1 << CONTROL_EP));
	pUOReg->DCSR.DOEPMSK = CTRL_OUT_EP_SETUP_PHASE_DONE |
				AHB_ERROR | TRANSFER_DONE;
	pUOReg->DCSR.DIEPMSK = INTKN_TXFEMP | NON_ISO_IN_EP_TIMEOUT |
				AHB_ERROR | TRANSFER_DONE;

	/* Rx FIFO Size */
	pUOReg->GCSR.GRXFSIZ = RX_FIFO_SIZE;

	/* Non Periodic Tx FIFO Size */
	pUOReg->GCSR.GNPTXFSIZ = NPTX_FIFO_SIZE << 16 |
				NPTX_FIFO_START_ADDR << 0;

	/* clear all out ep nak */
	for (i = 0; i < 16; i++)
		pUOReg->DCSR.DEPOR[i].DOEPCTL |= (DEPCTL_EPENA | DEPCTL_CNAK);

	/*clear device address */
	pUOReg->DCSR.DCFG &= ~(0x7F << 4);
}

static s32 nx_usb_set_init(USBBOOTSTATUS *pUSBBootStatus)
{
	u32 status = pUOReg->DCSR.DSTS; /* System status read */
	union {
		u32 AID;
		u16 SID[2];
		u8 BID[4];
	} USBID;

	pUSBBootStatus->bHeaderReceived = CFALSE;
	pUSBBootStatus->iRxHeaderSize = 0;

	/* Set if Device is High speed or Full speed */
	if (((status & 0x6) >> 1) == USB_HIGH) {
		pUSBBootStatus->speed = USB_HIGH;
		printf("High Speed Detection\r\n");
	} else if (((status & 0x6) >> 1) == USB_FULL) {
		pUSBBootStatus->speed = USB_FULL;
		printf("Full Speed Detection\r\n");
	} else {
		printf("**** Error:Neither High_Speed nor Full_Speed\r\n");
		return CFALSE;
	}

	/* set endpoint */
	/* Unmask NX_OTG_DAINT source */
	pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPINT = 0xFF;
	pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPINT = 0xFF;
	pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPINT = 0xFF;
	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPINT = 0xFF;

	/* Init For Ep0*/
	if (pUSBBootStatus->speed == USB_HIGH) {
		pUSBBootStatus->ctrl_max_pktsize = HIGH_MAX_PKT_SIZE_EP0;
		pUSBBootStatus->bulkin_max_pktsize = HIGH_MAX_PKT_SIZE_EP1;
		pUSBBootStatus->bulkout_max_pktsize = HIGH_MAX_PKT_SIZE_EP2;
		pUSBBootStatus->DeviceDescriptor = gs_DeviceDescriptorHS;
		pUSBBootStatus->ConfigDescriptor = gs_ConfigDescriptorHS;

		/*MPS:64bytes */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			((1 << 26) | (CONTROL_EP << 11) | (0 << 0));
		/*ep0 enable, clear nak */
		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPCTL =
			(1u << 31) | (1 << 26) | (0 << 0);
	} else {
		pUSBBootStatus->ctrl_max_pktsize = FULL_MAX_PKT_SIZE_EP0;
		pUSBBootStatus->bulkin_max_pktsize = FULL_MAX_PKT_SIZE_EP1;
		pUSBBootStatus->bulkout_max_pktsize = FULL_MAX_PKT_SIZE_EP2;
		pUSBBootStatus->DeviceDescriptor = gs_DeviceDescriptorFS;
		pUSBBootStatus->ConfigDescriptor = gs_ConfigDescriptorFS;

		/*MPS:8bytes */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			((1 << 26) | (CONTROL_EP << 11) | (3 << 0));
		/*ep0 enable, clear nak */
		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPCTL =
			(1u << 31) |(1 << 26) | (3 << 0);
	}

	//----------------------------------------------------------------------
	// get VID & PID for USBD
	//----------------------------------------------------------------------
#if defined(CHIPID_NXP4330)
	USBID.SID[1] = USBD_VID;
	USBID.SID[0] = USBD_PID;
#else

	USBID.AID = pReg_ECID->ECID[3];

	if ((USBID.SID[0] == 0) || (USBID.SID[1] == 0)) {
		USBID.SID[1] = USBD_VID;
		USBID.SID[0] = USBD_PID;
	} else {
		USBID.SID[1] = 0x04E8;
		USBID.SID[0] = 0x1234;
	}
#endif
	//    SYSMSG("USBD VID = %04X, PID = %04X\r\n", g_USBD_VID, g_USBD_PID);

	pUSBBootStatus->DeviceDescriptor[8]  = (u8)(USBID.BID[2]);  //  8 vendor ID LSB
	pUSBBootStatus->DeviceDescriptor[9]  = (u8)(USBID.BID[3]);  //  9 vendor ID MSB
	pUSBBootStatus->DeviceDescriptor[10] = (u8)(USBID.BID[0]);  // 10 product ID LSB    (second product)
	pUSBBootStatus->DeviceDescriptor[11] = (u8)(USBID.BID[1]);  // 11 product ID MSB

	/* set_opmode */
	pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP | INT_IN_EP |
				INT_ENUMDONE | INT_RESET | INT_SUSPEND |
				INT_RX_FIFO_NOT_EMPTY;

	pUOReg->GCSR.GAHBCFG = MODE_SLAVE | BURST_SINGLE | GBL_INT_UNMASK;

	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPTSIZ =
		(1 << 19) | (pUSBBootStatus->bulkout_max_pktsize << 0);

	pUOReg->DCSR.DEPOR[BULK_IN_EP].DOEPTSIZ = (1 << 19) | (0 << 0);

	/*bulk out ep enable, clear nak, bulk, usb active, next ep2, max pkt */
	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL =
		1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
		pUSBBootStatus->bulkout_max_pktsize << 0;

	/*bulk in ep enable, clear nak, bulk, usb active, next ep1, max pkt */
	pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
		0u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
		pUSBBootStatus->bulkin_max_pktsize << 0;

	return CTRUE;
}

static void nx_usb_pkt_receive(USBBOOTSTATUS *pUSBBootStatus,
		struct NX_SecondBootInfo *pTBI)
{
	u32 rx_status;
	u32 fifo_cnt_byte;

	rx_status = pUOReg->GCSR.GRXSTSP;
	/* CRC Check for Global Boot Status */
	g_USBBootStatus = pUSBBootStatus;

	if ((rx_status & (0xf << 17)) == SETUP_PKT_RECEIVED) {
		dprintf("SETUP_PKT_RECEIVED\r\n");
		nx_usb_ep0_int_hndlr(pUSBBootStatus);
	} else if ((rx_status & (0xf << 17)) == OUT_PKT_RECEIVED) {
		fifo_cnt_byte = (rx_status & 0x7ff0) >> 4;
		dprintf("OUT_PKT_RECEIVED\r\n");

		if ((rx_status & BULK_OUT_EP)&&(fifo_cnt_byte)) {
			nx_usb_int_bulkout(pUSBBootStatus, pTBI, fifo_cnt_byte);
			pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP |
						INT_IN_EP | INT_ENUMDONE |
						INT_RESET | INT_SUSPEND |
						INT_RX_FIFO_NOT_EMPTY;
			return;
		}
	} else if ((rx_status & (0xf << 17)) == GLOBAL_OUT_NAK) {
		dprintf("GLOBAL_OUT_NAK\r\n");
	} else if ((rx_status & (0xf << 17)) == OUT_TRNASFER_COMPLETED) {
		dprintf("OUT_TRNASFER_COMPLETED\r\n");
	} else if ((rx_status & (0xf << 17)) == SETUP_TRANSACTION_COMPLETED) {
		dprintf("SETUP_TRANSACTION_COMPLETED\r\n");
	} else {
		dprintf("Reserved\r\n");
	}
}

static void nx_usb_transfer(USBBOOTSTATUS *pUSBBootStatus)
{
	u32 ep_int;
	u32 ep_int_status;

	ep_int = pUOReg->DCSR.DAINT;

	if (ep_int & (1 << CONTROL_EP)) {
		ep_int_status = pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPINT;

		if (ep_int_status & INTKN_TXFEMP) {

			while ((pUOReg->GCSR.GNPTXSTS & 0xFFFF) <
					pUSBBootStatus->ctrl_max_pktsize);

			nx_usb_transfer_ep0(pUSBBootStatus);
		}

		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPINT = ep_int_status;
	}

	if (ep_int & ((1 << CONTROL_EP) << 16)) {
		ep_int_status = pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPINT;

		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPTSIZ =
			(1 << 29) | (1 << 19) | (8 << 0);
		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPCTL =
			1u << 31 | 1 << 26; /*ep0 enable, clear nak */

		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPINT =
			ep_int_status; /* Interrupt Clear */
	}

	if (ep_int & (1 << BULK_IN_EP)) {
		ep_int_status = pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPINT;

		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPINT =
			ep_int_status; /* Interrupt Clear */

		if (ep_int_status & INTKN_TXFEMP)
			nx_usb_int_bulkin(pUSBBootStatus);
	}

	if (ep_int & ((1 << BULK_OUT_EP) << 16)) {
		ep_int_status = pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPINT;
		pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPINT =
			ep_int_status; /* Interrupt Clear */
	}
}

static void nx_udc_int_hndlr(USBBOOTSTATUS *pUSBBootStatus,
		struct NX_SecondBootInfo *pTBI)
{
	u32 int_status;
	s32 tmp;

	int_status = pUOReg->GCSR.GINTSTS; /* Core Interrupt Register */

	if (int_status & INT_RESET) {
		dprintf("INT_RESET\r\n");

		nx_usb_reset(pUSBBootStatus);
	}

	if (int_status & INT_ENUMDONE) {
		dprintf("INT_ENUMDONE :");

		tmp = nx_usb_set_init(pUSBBootStatus);
		if (tmp == CFALSE) {
			pUOReg->GCSR.GINTSTS = int_status; /* Interrupt Clear */
			return;
		}
	}

	if (int_status & INT_RESUME) {
		dprintf("INT_RESUME\r\n");
	}

	if (int_status & INT_SUSPEND) {
		dprintf("INT_SUSPEND\r\n");
	}

	if (int_status & INT_RX_FIFO_NOT_EMPTY) {
		dprintf("INT_RX_FIFO_NOT_EMPTY\r\n");
		/* Read only register field */

		pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP | INT_IN_EP |
					INT_ENUMDONE | INT_RESET | INT_SUSPEND;
		nx_usb_pkt_receive(pUSBBootStatus, pTBI);
		pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP | INT_IN_EP |
					INT_ENUMDONE | INT_RESET | INT_SUSPEND |
					INT_RX_FIFO_NOT_EMPTY;
	}

	if ((int_status & INT_IN_EP) || (int_status & INT_OUT_EP)) {
		dprintf("INT_IN or OUT_EP\r\n");
		/* Read only register field */

		nx_usb_transfer(pUSBBootStatus);
	}
	pUOReg->GCSR.GINTSTS = int_status; /* Interrupt Clear */
}
void udelay(u32 utime)
{
	register volatile u32 i;
	for (; utime > 0; utime--)
		for (i = 106; i > 0; i--);
}

cbool iUSBBOOT(struct NX_SecondBootInfo *pTBI)
{
	USBBOOTSTATUS USBBootStatus;
	USBBOOTSTATUS *pUSBBootStatus = &USBBootStatus;
	ResetCon(RI_USB20OTG_MODULE_i_nRST, CTRUE);	// reset on
	ResetCon(RI_USB20OTG_MODULE_i_nRST, CFALSE);	// reset negate

	/* CRC Check for variables */
	g_TBI = pTBI;

	// scale mode ( 0: real silicon, 1: test simul, 2, 3)
	pReg_Tieoff->TIEOFFREG[12] &= ~0x3;
	// 8: enable, 9:phy word interface (0: 8 bit, 1: 16 bit)
	pReg_Tieoff->TIEOFFREG[14] |= 3 << 8;
	// VBUSVLDEXT=1, VBUSVLDEXTSEL=1, POR=0
	pReg_Tieoff->TIEOFFREG[13] = 0xA3006C00;
	pReg_Tieoff->TIEOFFREG[13] = 0xA3006C80;	// POR_ENB=1
	udelay(40);	// 40us delay need.

	pReg_Tieoff->TIEOFFREG[13] = 0xA3006C88;	// nUtmiResetSync : 00000001
	udelay(1);					// 10 clock need

	pReg_Tieoff->TIEOFFREG[13] = 0xA3006C8C; // nResetSync : 00000001
	udelay(1);				 // 10 clock need

	/* usb core soft reset */
	pUOReg->GCSR.GRSTCTL = CORE_SOFT_RESET;
	while (!(pUOReg->GCSR.GRSTCTL & AHB_MASTER_IDLE))
		;

	/* init_core */
	pUOReg->GCSR.GAHBCFG = PTXFE_HALF | NPTXFE_HALF | MODE_SLAVE |
				BURST_SINGLE | GBL_INT_UNMASK;
	pUOReg->GCSR.GUSBCFG =
		(0 << 15) |	/* PHY Low Power Clock sel */
		(1 << 14) |	/* Non-Periodic TxFIFO Rewind Enable */
		(5 << 10) |	/* Turnaround time */
		(0 <<  9) |	/* 0:HNP disable, 1:HNP enable */
		(0 <<  8) |	/* 0:SRP disable, 1:SRP enable */
		(0 <<  7) |	/* ULPI DDR sel */
		(0 <<  6) |	/* 0: high speed utmi+, 1: full speed serial */
		(0 <<  4) |	/* 0: utmi+, 1:ulpi */
		(1 <<  3) |	/* phy i/f  0:8bit, 1:16bit */
		(7 <<  0); 	/* HS/FS Timeout**/

	/* check current mode */
	if ((pUOReg->GCSR.GINTSTS & 0x1) == INT_DEV_MODE) {
		/* soft disconnect on */
		pUOReg->DCSR.DCTL |= SOFT_DISCONNECT;
		udelay(10);
		/* soft disconnect off */
		pUOReg->DCSR.DCTL &= ~SOFT_DISCONNECT;

		/* usb init device */
		/* [][1: full speed(30Mhz) 0:high speed]*/
		pUOReg->DCSR.DCFG = 1 << 18;// | pUSBBootStatus->speed<<0;
		pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP | INT_IN_EP |
					INT_ENUMDONE | INT_RESET | INT_SUSPEND |
					INT_RX_FIFO_NOT_EMPTY;
	}

	pUSBBootStatus->CurConfig = 0;
	pUSBBootStatus->CurInterface = 0;
	pUSBBootStatus->CurSetting = 0;
	pUSBBootStatus->speed = USB_HIGH;
	pUSBBootStatus->ep0_state = EP0_STATE_INIT;

	printf("bl2 usb boot ready!\r\n");

	pUSBBootStatus->bDownLoading = CTRUE;
	while (pUSBBootStatus->bDownLoading) {
		if (pUOReg->GCSR.GINTSTS & (WkUpInt | OEPInt | IEPInt |
					EnumDone | USBRst | USBSusp | RXFLvl)) {
			nx_udc_int_hndlr(pUSBBootStatus, pTBI);
			pUOReg->GCSR.GINTSTS = 0xFFFFFFFF;
		}
	}
	/* usb core soft reset */
	pUOReg->GCSR.GRSTCTL = CORE_SOFT_RESET;
	while (!(pUOReg->GCSR.GRSTCTL & AHB_MASTER_IDLE))
		;

	pReg_Tieoff->TIEOFFREG[13] &= ~(1 << 3);	//nUtmiResetSync = 0
	pReg_Tieoff->TIEOFFREG[13] &= ~(1 << 2);	//nResetSync = 0
	pReg_Tieoff->TIEOFFREG[13] |=   3 << 7;		//POR_ENB=1, POR=1

	ResetCon(RI_USB20OTG_MODULE_i_nRST, CTRUE);  // reset on

	printf("\r\n\nusb image download is done!\r\n\n");

	printf("USB Load Address = 0x%08X "
		"Launch Address = 0x%08X, "
		"size = %d bytes\r\n",
			pTBI->LOADADDR, pTBI->LAUNCHADDR, pTBI->LOADSIZE);

	return CTRUE;
}

#define BL2_FIXED_SIZE			(50*1024)
#define ARMV7_DISPATCHER_FIXED		(28*1024)

static int load_usbdown(struct nx_bootheader *bh, struct NX_SecondBootInfo *nbh,
			int slot, int encryped)
{
	struct nx_bootheader *hdr, *header;
	int *down_addr, *image_addr;
	int fixed_size, header_size = sizeof(struct nx_bootheader);

	/* step xx. get the "fip-nonsecure-usb.bin" download address */
	hdr = (struct nx_bootheader *)bh;
	down_addr = (int*)(&hdr->tbbi._reserved3);
	hdr = (struct nx_bootheader *)down_addr[0];

	/* step xx. get the boot-loader fixed size */
	if (slot == SECURE_DISPATCHER)
		fixed_size = BL2_FIXED_SIZE;
	else if (slot == NON_SECURE_BL)
		fixed_size = (BL2_FIXED_SIZE + ARMV7_DISPATCHER_FIXED);
	else
		fixed_size = 0;

	header = (struct nx_bootheader *)((unsigned int)hdr
		+ (unsigned int)(fixed_size));

	if (header->tbbi.signature != HEADER_ID) {
		ERROR("Wrong Boot Sinature!! (0x%08X)\r\n", header->tbbi.signature);
		return -1;
	}

	image_addr= ((char*)header + header_size);
	memcpy((void*)header->tbbi.loadaddr, ((void*)image_addr),
		header->tbbi.loadsize);

	nbh->LOADADDR   = header->tbbi.loadaddr;
	nbh->LAUNCHADDR = header->tbbi.startaddr;

	encryped = encryped;

#ifdef SECURE_ON
	return readimage((u8 *)header, (u8 *)bh,
			 (u8 *)header->tbbi.loadaddr);
#else
	return 0;
#endif
}

int plat_load_usbdown(struct nx_bootheader *pBH,
			   struct NX_SecondBootInfo *pTDS,
			   struct NX_SecondBootInfo *pTBS ,
			   struct NX_SecondBootInfo *pTBNS,
			   int is_resume)
{
	int ret;

	ret = load_usbdown(pBH, pTDS, SECURE_DISPATCHER, 1);
	if ((ret != -1) && !is_resume) {
		load_usbdown(pBH, pTBNS, NON_SECURE_BL, 1);
	#if 0	// Secure OS
		if (ret != -1) {
			load_usbdown(pBH, pTBS, SECURE_OS, 1);
		}
	#else
		pTBS->LOADADDR = 0;
		pTBS->LAUNCHADDR = 0;
	#endif
	}

	return 1;
}

