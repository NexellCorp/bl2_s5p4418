/*
 * Copyright (C) 2012 Nexell Co., All Rights Reserved
 * Nexell Co. Proprietary & Confidential
 *
 * nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular purpose.
 *
 * Module	: Base
 * File		: nx_chip.h
 * Description	: support chip information
 * Author	: Goofy
 * History	: 2012-06-27  Gamza remove OFFSET_OF_refer to 
 *		  PHY_BASEADDR_LIST( x ) in nx_prototype.h
 * 		  2010.07.19	Hans modify to nxp-2120
 *		  2008.04.17	Goofy first draft.
 */


#ifndef __NX_CHIP_P4330_H__
#define __NX_CHIP_P4330_H__


#define NUMBER_OF_SIMIO_MODULE					1
#define PHY_BASEADDR_SIMIO_MODULE				 0x82000000

#define NUMBER_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE		1
#define PHY_BASEADDR_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE	0x40000000

#define NUMBER_OF_MCUSTOP_MODULE				1
#define PHY_BASEADDR_MCUSTOP_MODULE				0xC0051000

#define NUMBER_OF_AXISRAM_MODULE				1
#define PHY_BASEADDR_AXISRAM_MODULE				0xFFFF0000

#define NUMBER_OF_DMA_MODULE					2
#define PHY_BASEADDR_DMA0_MODULE				0xC0000000
#define PHY_BASEADDR_DMA1_MODULE				0xC0001000

#define NUMBER_OF_DREX_MODULE					1
#define PHY_BASEADDR_DREX_MODULE_CH0_APB			0xC00E0000
#define PHY_BASEADDR_DREX_MODULE_CH1_APB			0xC00E1000

#define NUMBER_OF_CLKPWR_MODULE					1
#define PHY_BASEADDR_CLKPWR_MODULE				0xC0010000

#define NUMBER_OF_INTC_MODULE					1
#define PHY_BASEADDR_INTC_MODULE				0xC0002000

#define NUMBER_OF_pl01115_Uart_modem_MODULE			1
#define PHY_BASEADDR_pl01115_Uart_modem_MODULE			0xC00A0000

#define NUMBER_OF_UART_MODULE					2
#define PHY_BASEADDR_UART0_MODULE				0xC00A1000
#define PHY_BASEADDR_UART1_MODULE				0xC00A2000

#define NUMBER_OF_pl01115_Uart_nodma_MODULE			3
#define PHY_BASEADDR_pl01115_Uart_nodma0_MODULE			0xC00A3000
#define PHY_BASEADDR_pl01115_Uart_nodma1_MODULE			0xC006D000
#define PHY_BASEADDR_pl01115_Uart_nodma2_MODULE			0xC006F000

#define NUMBER_OF_SSP_MODULE					3
#define PHY_BASEADDR_SSP0_MODULE				0xC005B000
#define PHY_BASEADDR_SSP1_MODULE				0xC005C000
#define PHY_BASEADDR_SSP2_MODULE				0xC005F000

#define NUMBER_OF_I2C_MODULE					3
#define PHY_BASEADDR_I2C0_MODULE				0xC00A4000
#define PHY_BASEADDR_I2C1_MODULE				0xC00A5000
#define PHY_BASEADDR_I2C2_MODULE				0xC00A6000

#define NUMBER_OF_I2S_MODULE					3
#define PHY_BASEADDR_I2S0_MODULE				0xC0055000
#define PHY_BASEADDR_I2S1_MODULE				0xC0056000
#define PHY_BASEADDR_I2S2_MODULE				0xC0057000

#define NUMBER_OF_DEINTERLACE_MODULE				1
#define PHY_BASEADDR_DEINTERLACE_MODULE				0xC0065000

#define NUMBER_OF_SCALER_MODULE					1
#define PHY_BASEADDR_SCALER_MODULE				0xC0066000

#define NUMBER_OF_AC97_MODULE					1
#define PHY_BASEADDR_AC97_MODULE				0xC0058000

#define NUMBER_OF_SPDIFRX_MODULE				1
#define PHY_BASEADDR_SPDIFRX_MODULE				0xC005A000

#define NUMBER_OF_SPDIFTX_MODULE				1
#define PHY_BASEADDR_SPDIFTX_MODULE				0xC0059000

#define NUMBER_OF_TIMER_MODULE					1
#define PHY_BASEADDR_TIMER_MODULE				0xC0017000

#define NUMBER_OF_PWM_MODULE					1
#define PHY_BASEADDR_PWM_MODULE					0xC0018000


#define NUMBER_OF_WDT_MODULE					1
#define PHY_BASEADDR_WDT_MODULE					0xC0019000

#define NUMBER_OF_MPEGTSI_MODULE				1
#define PHY_BASEADDR_MPEGTSI_MODULE				0xC005D000

#define NUMBER_OF_DISPLAYTOP_MODULE				1
#define PHY_BASEADDR_DISPLAYTOP_MODULE				0xC0100000

#define NUMBER_OF_VIP_MODULE					2
#define PHY_BASEADDR_VIP0_MODULE				0xC0064000
#define PHY_BASEADDR_VIP1_MODULE				0xC0063000

#define NUMBER_OF_MIPI_MODULE					1
#define PHY_BASEADDR_MIPI_MODULE				0xC00D0000

#define NUMBER_OF_MALI400_MODULE				1
#define PHY_BASEADDR_MALI400_MODULE				0xC0070000

#define NUMBER_OF_ADC_MODULE					1
#define PHY_BASEADDR_ADC_MODULE					0xC0053000

#define NUMBER_OF_PPM_MODULE					1
#define PHY_BASEADDR_PPM_MODULE					0xC0054000

#define NUMBER_OF_SDMMC_MODULE					3
#define PHY_BASEADDR_SDMMC0_MODULE				0xC0062000
#define PHY_BASEADDR_SDMMC1_MODULE				0xC0068000
#define PHY_BASEADDR_SDMMC2_MODULE				0xC0069000

#define NUMBER_OF_CODA960_MODULE				1
#define PHY_BASEADDR_CODA960_MODULE_APB0			0xC0080000
#define PHY_BASEADDR_CODA960_MODULE_APB1			0xC0081000
#define PHY_BASEADDR_CODA960_MODULE_APB2			0xC0082000
#define PHY_BASEADDR_CODA960_MODULE_APB3			0xC0083000

#define NUMBER_OF_DWC_GMAC_MODULE				1
#define PHY_BASEADDR_DWC_GMAC_MODULE_APB0			0xC0060000
#define PHY_BASEADDR_DWC_GMAC_MODULE_APB1			0xC0061000

#define NUMBER_OF_USB20OTG_MODULE				1
#define PHY_BASEADDR_USB20OTG_MODULE_AHBS0			0xC0040000
#define PHY_BASEADDR_USB20OTG_MODULE_APB			0xC006C000

#define NUMBER_OF_USB20HOST_MODULE				1
#define PHY_BASEADDR_USB20HOST_MODULE_EHCI_S_ABH		0xC0030000
#define PHY_BASEADDR_USB20HOST_MODULE_OHCI_S_ABH		0xC0020000
#define PHY_BASEADDR_USB20HOST_MODULE_APB			0xC006A000

#define NUMBER_OF_CAN_MODULE					2
#define PHY_BASEADDR_CAN0_MODULE				0xC00CE000
#define PHY_BASEADDR_CAN1_MODULE				0xC00CF000

#define NUMBER_OF_ECID_MODULE					1
#define PHY_BASEADDR_ECID_MODULE				0xC0067000

#define NUMBER_OF_RSTCON_MODULE					1
#define PHY_BASEADDR_RSTCON_MODULE				0xC0012000

#define NUMBER_OF_A3BM_AXI_TOP_MASTER_BUS_MODULE		1
#define PHY_BASEADDR_A3BM_AXI_TOP_MASTER_BUS_MODULE		0xC0052000

#define NUMBER_OF_A3BM_AXI_BOTTOM_MASTER_BUS_MODULE		1
#define PHY_BASEADDR_A3BM_AXI_BOTTOM_MASTER_BUS_MODULE_S3	0x0
#define PHY_BASEADDR_A3BM_AXI_BOTTOM_MASTER_BUS_MODULE_APB_BOTTOMBUS	0xC0050000

#define NUMBER_OF_A3BM_AXI_PERI_BUS_MODULE			1
#define PHY_BASEADDR_A3BM_AXI_PERI_BUS_MODULE			0xC0000000

#define NUMBER_OF_A3BM_AXI_DISPLAY_BUS_MODULE			1
#define PHY_BASEADDR_A3BM_AXI_DISPLAY_BUS_MODULE		0xC005E000

#define NUMBER_OF_GPIO_MODULE					5
#define PHY_BASEADDR_GPIOA_MODULE				0xC001A000
#define PHY_BASEADDR_GPIOB_MODULE				0xC001B000
#define PHY_BASEADDR_GPIOC_MODULE				0xC001C000
#define PHY_BASEADDR_GPIOD_MODULE				0xC001D000
#define PHY_BASEADDR_GPIOE_MODULE				0xC001E000

#define NUMBER_OF_CRYPTO_MODULE					1
#define PHY_BASEADDR_CRYPTO_MODULE				0xC0015000

#define NUMBER_OF_PDM_MODULE					1
#define PHY_BASEADDR_PDM_MODULE					0xC0014000

#define NUMBER_OF_TIEOFF_MODULE					1
#define PHY_BASEADDR_TIEOFF_MODULE				0xC0011000

#define NUMBER_OF_CLKGEN_MODULE					40
#define PHY_BASEADDR_CLKGEN0_MODULE				0xC00BB000
#define PHY_BASEADDR_CLKGEN1_MODULE				0xC00BC000
#define PHY_BASEADDR_CLKGEN2_MODULE				0xC00BD000
#define PHY_BASEADDR_CLKGEN3_MODULE				0xC00BE000
#define PHY_BASEADDR_CLKGEN4_MODULE				0xC00BF000
#define PHY_BASEADDR_CLKGEN5_MODULE				0xC00C0000
#define PHY_BASEADDR_CLKGEN6_MODULE				0xC00AE000
#define PHY_BASEADDR_CLKGEN7_MODULE				0xC00AF000
#define PHY_BASEADDR_CLKGEN8_MODULE				0xC00B0000
#define PHY_BASEADDR_CLKGEN9_MODULE				0xC00CA000
#define PHY_BASEADDR_CLKGEN10_MODULE				0xC00C8000
#define PHY_BASEADDR_CLKGEN11_MODULE				0xC00B8000
#define PHY_BASEADDR_CLKGEN12_MODULE				0xC00B7000
#define PHY_BASEADDR_CLKGEN13_MODULE				0xC00BA000
#define PHY_BASEADDR_CLKGEN14_MODULE				0xC00B9000
#define PHY_BASEADDR_CLKGEN15_MODULE				0xC00B2000
#define PHY_BASEADDR_CLKGEN16_MODULE				0xC00B3000
#define PHY_BASEADDR_CLKGEN17_MODULE				0xC00B4000
#define PHY_BASEADDR_CLKGEN18_MODULE				0xC00C5000
#define PHY_BASEADDR_CLKGEN19_MODULE				0xC00CC000
#define PHY_BASEADDR_CLKGEN20_MODULE				0xC00CD000
#define PHY_BASEADDR_CLKGEN21_MODULE				0xC00C3000
#define PHY_BASEADDR_CLKGEN22_MODULE				0xC00A9000
#define PHY_BASEADDR_CLKGEN23_MODULE				0xC00AA000
#define PHY_BASEADDR_CLKGEN24_MODULE				0xC00A8000
#define PHY_BASEADDR_CLKGEN25_MODULE				0xC00AB000
#define PHY_BASEADDR_CLKGEN26_MODULE				0xC006E000
#define PHY_BASEADDR_CLKGEN27_MODULE				0xC0084000
#define PHY_BASEADDR_CLKGEN28_MODULE				0xC00B5000
#define PHY_BASEADDR_CLKGEN29_MODULE				0xC00C4000
#define PHY_BASEADDR_CLKGEN30_MODULE				0xC00C2000
#define PHY_BASEADDR_CLKGEN31_MODULE				0xC00C1000
#define PHY_BASEADDR_CLKGEN32_MODULE				0xC006B000
#define PHY_BASEADDR_CLKGEN33_MODULE				0xC00C7000
#define PHY_BASEADDR_CLKGEN34_MODULE				0xC00C6000
#define PHY_BASEADDR_CLKGEN35_MODULE				0xC00B6000
#define PHY_BASEADDR_CLKGEN36_MODULE				0xC00CB000
#define PHY_BASEADDR_CLKGEN37_MODULE				0xC00AC000
#define PHY_BASEADDR_CLKGEN38_MODULE				0xC00AD000
#define PHY_BASEADDR_CLKGEN39_MODULE				0xC00A7000

#define NX_INTC_NUM_OF_INT		60

enum {
	IN_MCUSTOP_MODULE				= 0,
	IN_DMA0_MODULE					= 1,
	IN_DMA1_MODULE					= 2,
	IN_CLKPWR_MODULE_INTREQPWR			= 3,
	IN_CLKPWR_MODULE_ALIVEIRQ			= 4,
	IN_CLKPWR_MODULE_RTCIRQ				= 5,
	IN_pl01115_Uart_modem_MODULE			= 6,
	IN_UART0_MODULE					= 7,
	IN_UART1_MODULE					= 8,
	IN_pl01115_Uart_nodma0_MODULE			= 9,
	IN_pl01115_Uart_nodma1_MODULE			= 10,
	IN_pl01115_Uart_nodma2_MODULE			= 11,
	IN_SSP0_MODULE					= 12,
	IN_SSP1_MODULE					= 13,
	IN_SSP2_MODULE					= 14,
	IN_I2C0_MODULE					= 15,
	IN_I2C1_MODULE					= 16,
	IN_I2C2_MODULE					= 17,
	IN_DEINTERLACE_MODULE				= 18,
	IN_SCALER_MODULE				= 19,
	IN_AC97_MODULE					= 20,
	IN_SPDIFRX_MODULE				= 21,
	IN_SPDIFTX_MODULE				= 22,
	IN_TIMER_MODULE_INT0				= 23,
	IN_TIMER_MODULE_INT1				= 24,
	IN_TIMER_MODULE_INT2				= 25,
	IN_TIMER_MODULE_INT3				= 26,
	IN_PWM_MODULE_INT0				= 27,
	IN_PWM_MODULE_INT1				= 28,
	IN_PWM_MODULE_INT2				= 29,
	IN_PWM_MODULE_INT3				= 30,
	IN_WDT_MODULE					= 31,
	IN_MPEGTSI_MODULE				= 32,
	IN_DISPLAYTOP_MODULE_DUALDISPLAY_PRIMIRQ	= 33,
	IN_DISPLAYTOP_MODULE_DUALDISPLAY_SECONDIRQ	= 34,
	IN_DISPLAYTOP_MODULE_RESCONV_IRQ		= 35,
	IN_DISPLAYTOP_MODULE_HDMI_IRQ			= 36,
	IN_VIP0_MODULE					= 38,
	IN_VIP1_MODULE					= 37,
	IN_MIPI_MODULE					= 39,
	IN_MALI400_MODULE				= 40,
	IN_ADC_MODULE					= 41,
	IN_PPM_MODULE					= 42,
	IN_SDMMC0_MODULE				= 43,
	IN_SDMMC1_MODULE				= 44,
	IN_SDMMC2_MODULE				= 45,
	IN_CODA960_MODULE_HOST_INTRPT			= 46,
	IN_CODA960_MODULE_JPG_INTRPT			= 47,
	IN_DWC_GMAC_MODULE				= 48,
	IN_USB20OTG_MODULE				= 49,
	IN_USB20HOST_MODULE				= 50,
	IN_CAN0_MODULE					= 51,
	IN_CAN1_MODULE					= 52,
	IN_GPIOA_MODULE					= 53,
	IN_GPIOB_MODULE					= 54,
	IN_GPIOC_MODULE					= 55,
	IN_GPIOD_MODULE					= 56,
	IN_GPIOE_MODULE					= 57,
	IN_CRYPTO_MODULE				= 58,
	IN_PDM_MODULE					= 59
};


#define NUMBER_OF_RESET_MODULE_PIN 69
enum {
	RI_AC97_MODULE_PRESETn = 0,
	RI_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nCPURESET1 = 1,
	RI_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nCPURESET2 = 2,
	RI_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nCPURESET3 = 3,
	RI_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nWDRESET1 = 4,
	RI_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nWDRESET2 = 5,
	RI_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nWDRESET3 = 6,
	RI_CRYPTO_MODULE_i_nRST = 7,
	RI_DEINTERLACE_MODULE_i_nRST = 8,
	RI_DISPLAYTOP_MODULE_i_Top_nRST = 9,
	RI_DISPLAYTOP_MODULE_i_DualDisplay_nRST = 10,
	RI_DISPLAYTOP_MODULE_i_ResConv_nRST = 11,
	RI_DISPLAYTOP_MODULE_i_LCDIF_nRST = 12,
	RI_DISPLAYTOP_MODULE_i_HDMI_nRST = 13,
	RI_DISPLAYTOP_MODULE_i_HDMI_VIDEO_nRST = 14,
	RI_DISPLAYTOP_MODULE_i_HDMI_SPDIF_nRST = 15,
	RI_DISPLAYTOP_MODULE_i_HDMI_TMDS_nRST = 16,
	RI_DISPLAYTOP_MODULE_i_HDMI_PHY_nRST = 17,
	RI_DISPLAYTOP_MODULE_i_LVDS_nRST = 18,
	RI_ECID_MODULE_i_nRST = 19,
	RI_I2C0_MODULE_PRESETn = 20,
	RI_I2C1_MODULE_PRESETn = 21,
	RI_I2C2_MODULE_PRESETn = 22,
	RI_I2S0_MODULE_PRESETn = 23,
	RI_I2S1_MODULE_PRESETn = 24,
	RI_I2S2_MODULE_PRESETn = 25,
	RI_DREX_MODULE_CRESETn = 26,
	RI_DREX_MODULE_ARESETn = 27,
	RI_DREX_MODULE_nPRST = 28,
	RI_MIPI_MODULE_i_nRST = 29,
	RI_MIPI_MODULE_i_DSI_I_PRESETn = 30,
	RI_MIPI_MODULE_i_CSI_I_PRESETn = 31,
	RI_MIPI_MODULE_i_PHY_S_RESETN = 32,
	RI_MIPI_MODULE_i_PHY_M_RESETN = 33,
	RI_MPEGTSI_MODULE_i_nRST = 34,
	RI_PDM_MODULE_i_nRST = 35,
	RI_TIMER_MODULE_PRESETn = 36,
	RI_PWM_MODULE_PRESETn = 37,
	RI_SCALER_MODULE_i_nRST = 38,
	RI_SDMMC0_MODULE_i_nRST = 39,
	RI_SDMMC1_MODULE_i_nRST = 40,
	RI_SDMMC2_MODULE_i_nRST = 41,
	RI_SPDIFRX_MODULE_PRESETn = 42,
	RI_SPDIFTX_MODULE_PRESETn = 43,
	RI_SSP0_MODULE_PRESETn = 44,
	RI_SSP0_MODULE_nSSPRST = 45,
	RI_SSP1_MODULE_PRESETn = 46,
	RI_SSP1_MODULE_nSSPRST = 47,
	RI_SSP2_MODULE_PRESETn = 48,
	RI_SSP2_MODULE_nSSPRST = 49,
	RI_UART0_MODULE_nUARTRST = 50,
	RI_pl01115_Uart_modem_MODULE_nUARTRST = 51,
	RI_UART1_MODULE_nUARTRST = 52,
	RI_pl01115_Uart_nodma0_MODULE_nUARTRST = 53,
	RI_pl01115_Uart_nodma1_MODULE_nUARTRST = 54,
	RI_pl01115_Uart_nodma2_MODULE_nUARTRST = 55,
	RI_USB20HOST_MODULE_i_nRST = 56,
	RI_USB20OTG_MODULE_i_nRST = 57,
	RI_WDT_MODULE_PRESETn = 58,
	RI_WDT_MODULE_nPOR = 59,
	RI_ADC_MODULE_nRST = 60,
	RI_CODA960_MODULE_i_areset_n = 61,
	RI_CODA960_MODULE_i_preset_n = 62,
	RI_CODA960_MODULE_i_creset_n = 63,
	RI_DWC_GMAC_MODULE_aresetn_i = 64,
	RI_MALI400_MODULE_nRST = 65,
	RI_PPM_MODULE_i_nRST = 66,
	RI_VIP1_MODULE_i_nRST = 68,
	RI_VIP0_MODULE_i_nRST = 67
};


//------------------------------------------------------------------------------
// Clock Generator : Module Index of Clock Generator
//------------------------------------------------------------------------------
#define NUMBER_OF_CLKGEN_MODULE 40
enum {
	CI_Inst_TIMER01_MODULE		= 0,
	CI_Inst_TIMER02_MODULE		= 1,
	CI_Inst_TIMER03_MODULE		= 2,
	CI_Inst_PWM01_MODULE		= 3,
	CI_Inst_PWM02_MODULE		= 4,
	CI_Inst_PWM03_MODULE		= 5,
	CI_I2C0_MODULE			= 6,
	CI_I2C1_MODULE			= 7,
	CI_I2C2_MODULE			= 8,
	CI_MIPI_MODULE			= 9,
	CI_DWC_GMAC_MODULE		= 10,
	CI_SPDIFTX_MODULE		= 11,
	CI_MPEGTSI_MODULE		= 12,
	CI_PWM_MODULE			= 13,
	CI_TIMER_MODULE			= 14,
	CI_I2S0_MODULE			= 15,
	CI_I2S1_MODULE			= 16,
	CI_I2S2_MODULE			= 17,
	CI_SDMMC0_MODULE		= 18,
	CI_SDMMC1_MODULE		= 19,
	CI_SDMMC2_MODULE		= 20,
	CI_MALI400_MODULE		= 21,
	CI_UART0_MODULE			= 22,
	CI_UART1_MODULE			= 23,
	CI_pl01115_Uart_modem_MODULE	= 24,
	CI_pl01115_Uart_nodma0_MODULE	= 25,
	CI_pl01115_Uart_nodma1_MODULE	= 26,
	CI_pl01115_Uart_nodma2_MODULE	= 27,
	CI_DEINTERLACE_MODULE		= 28,
	CI_PPM_MODULE			= 29,
	CI_VIP0_MODULE			= 30,
	CI_VIP1_MODULE			= 31,
	CI_USB20HOST_MODULE		= 32,
	CI_CODA960_MODULE		= 33,
	CI_CRYPTO_MODULE		= 34,
	CI_SCALER_MODULE		= 35,
	CI_PDM_MODULE			= 36,
	CI_SSP0_MODULE			= 37,
	CI_SSP1_MODULE			= 38,
	CI_SSP2_MODULE			= 39
};


//------------------------------------------------------------------------------
// DMA peripheral index of modules for the DMA controller.
//------------------------------------------------------------------------------
enum {
	DI_pl01115_Uart_modem_MODULE_UARTTXDMA	= 0,
	DI_pl01115_Uart_modem_MODULE_UARTRXDMA	= 1,
	DI_UART0_MODULE_UARTTXDMA		= 2,
	DI_UART0_MODULE_UARTRXDMA		= 3,
	DI_UART1_MODULE_UARTTXDMA		= 4,
	DI_UART1_MODULE_UARTRXDMA		= 5,
	DI_SSP0_MODULE_SSPTXDMA			= 6,
	DI_SSP0_MODULE_SSPRXDMA			= 7,
	DI_SSP1_MODULE_SSPTXDMA			= 8,
	DI_SSP1_MODULE_SSPRXDMA			= 9,
	DI_SSP2_MODULE_SSPTXDMA			= 10,
	DI_SSP2_MODULE_SSPRXDMA			= 11,
	DI_I2S0_MODULE_I2STXDMA			= 12,
	DI_I2S0_MODULE_I2SRXDMA			= 13,
	DI_I2S1_MODULE_I2STXDMA			= 14,
	DI_I2S1_MODULE_I2SRXDMA			= 15,
	DI_I2S2_MODULE_I2STXDMA			= 16,
	DI_I2S2_MODULE_I2SRXDMA			= 17,
	DI_AC97_MODULE_PCMOUTDMA		= 18,
	DI_AC97_MODULE_PCMINDMA			= 19,
	DI_AC97_MODULE_MICINDMA			= 20,
	DI_SPDIFRX_MODULE			= 21,
	DI_SPDIFTX_MODULE			= 22,
	DI_MPEGTSI_MODULE_MPTSIDMA0		= 23,
	DI_MPEGTSI_MODULE_MPTSIDMA1		= 24,
	DI_MPEGTSI_MODULE_MPTSIDMA2		= 25,
	DI_MPEGTSI_MODULE_MPTSIDMA3		= 26,
	DI_CRYPTO_MODULE_CRYPDMA_BR		= 27,
	DI_CRYPTO_MODULE_CRYPDMA_BW		= 28,
	DI_CRYPTO_MODULE_CRYPDMA_HR		= 29,
	DI_PDM_MODULE				= 30
};


#define	PI_GPIOA_GPIO_0_				((0 << 8) | ( 0 << 3) | 0)
#define	PI_DISPLAYTOP_o_DualDisplay_PADPrimVCLK		((0 << 8) | ( 0 << 3) | 1)
#define	PI_CLKPWR_i_PADTESTMODE_4_			((0 << 8) | ( 0 << 3) | 3)
#define	PI_GPIOA_GPIO_1_				((0 << 8) | ( 1 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_0_	((0 << 8) | ( 1 << 3) | 1)
#define	PI_GPIOA_GPIO_2_				((0 << 8) | ( 2 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_1_	((0 << 8) | ( 2 << 3) | 1)
#define	PI_CLKPWR_i_PADTESTMODE_0_			((0 << 8) | ( 2 << 3) | 3)
#define	PI_GPIOA_GPIO_3_				((0 << 8) | ( 3 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_2_	((0 << 8) | ( 3 << 3) | 1)
#define	PI_CLKPWR_i_PADTESTMODE_1_			((0 << 8) | ( 3 << 3) | 3)
#define	PI_GPIOA_GPIO_4_				((0 << 8) | ( 4 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_3_	((0 << 8) | ( 4 << 3) | 1)
#define	PI_CLKPWR_i_PADTESTMODE_2_			((0 << 8) | ( 4 << 3) | 3)
#define	PI_GPIOA_GPIO_5_				((0 << 8) | ( 5 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_4_	((0 << 8) | ( 5 << 3) | 1)
#define	PI_CLKPWR_i_PADTESTMODE_3_			((0 << 8) | ( 5 << 3) | 3)
#define	PI_GPIOA_GPIO_6_				((0 << 8) | ( 6 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_5_	((0 << 8) | ( 6 << 3) | 1)
#define	PI_GPIOA_GPIO_7_				((0 << 8) | ( 7 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_6_	((0 << 8) | ( 7 << 3) | 1)
#define	PI_GPIOA_GPIO_8_				((0 << 8) | ( 8 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_7_	((0 << 8) | ( 8 << 3) | 1)
#define	PI_GPIOA_GPIO_9_				((0 << 8) | ( 9 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_8_	((0 << 8) | ( 9 << 3) | 1)
#define	PI_GPIOA_GPIO_10_				((0 << 8) | (10 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_9_	((0 << 8) | (10 << 3) | 1)
#define	PI_GPIOA_GPIO_11_				((0 << 8) | (11 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_10_	((0 << 8) | (11 << 3) | 1)
#define	PI_GPIOA_GPIO_12_				((0 << 8) | (12 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_11_	((0 << 8) | (12 << 3) | 1)
#define	PI_GPIOA_GPIO_13_				((0 << 8) | (13 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_12_	((0 << 8) | (13 << 3) | 1)
#define	PI_GPIOA_GPIO_14_				((0 << 8) | (14 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_13_	((0 << 8) | (14 << 3) | 1)
#define	PI_GPIOA_GPIO_15_				((0 << 8) | (15 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_14_	((0 << 8) | (15 << 3) | 1)
#define	PI_GPIOA_GPIO_16_				((0 << 8) | (16 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_15_	((0 << 8) | (16 << 3) | 1)
#define	PI_GPIOA_GPIO_17_				((0 << 8) | (17 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_16_	((0 << 8) | (17 << 3) | 1)
#define	PI_GPIOA_GPIO_18_				((0 << 8) | (18 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_17_	((0 << 8) | (18 << 3) | 1)
#define	PI_GPIOA_GPIO_19_				((0 << 8) | (19 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_18_	((0 << 8) | (19 << 3) | 1)
#define	PI_GPIOA_GPIO_20_				((0 << 8) | (20 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_19_	((0 << 8) | (20 << 3) | 1)
#define	PI_GPIOA_GPIO_21_				((0 << 8) | (21 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_20_	((0 << 8) | (21 << 3) | 1)
#define	PI_GPIOA_GPIO_22_				((0 << 8) | (22 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_21_	((0 << 8) | (22 << 3) | 1)
#define	PI_GPIOA_GPIO_23_				((0 << 8) | (23 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_22_	((0 << 8) | (23 << 3) | 1)
#define	PI_GPIOA_GPIO_24_				((0 << 8) | (24 << 3) | 0)
#define	PI_DISPLAYTOP_DualDisplay_PrimPADRGB24_23_	((0 << 8) | (24 << 3) | 1)
#define	PI_GPIOA_GPIO_25_				((0 << 8) | (25 << 3) | 0)
#define	PI_DISPLAYTOP_o_DualDisplay_PrimPADnVSync	((0 << 8) | (25 << 3) | 1)
#define	PI_GPIOA_GPIO_26_				((0 << 8) | (26 << 3) | 0)
#define	PI_DISPLAYTOP_o_DualDisplay_PrimPADnHSync	((0 << 8) | (26 << 3) | 1)
#define	PI_GPIOA_GPIO_27_				((0 << 8) | (27 << 3) | 0)
#define	PI_DISPLAYTOP_o_DualDisplay_PrimPADDE		((0 << 8) | (27 << 3) | 1)
#define	PI_GPIOA_GPIO_28_				((0 << 8) | (28 << 3) | 0)
#define	PI_VIP1_i_ExtCLK				((0 << 8) | (28 << 3) | 1)
#define	PI_I2S2_I2SCODCLK				((0 << 8) | (28 << 3) | 2)
#define	PI_I2S1_I2SCODCLK				((0 << 8) | (28 << 3) | 3)
#define	PI_GPIOA_GPIO_30_				((0 << 8) | (30 << 3) | 0)
#define	PI_VIP1_i_VD_0_					((0 << 8) | (30 << 3) | 1)
#define	PI_MCUSTOP_SDEX_0_				((0 << 8) | (30 << 3) | 2)
#define	PI_I2S1_I2SBCLK					((0 << 8) | (30 << 3) | 3)
#define	PI_GPIOB_GPIO_0_				((1 << 8) | ( 0 << 3) | 0)
#define	PI_VIP1_i_VD_1_					((1 << 8) | ( 0 << 3) | 1)
#define	PI_MCUSTOP_SDEX_1_				((1 << 8) | ( 0 << 3) | 2)
#define	PI_I2S1_I2SLRCLK				((1 << 8) | ( 0 << 3) | 3)
#define	PI_GPIOB_GPIO_2_				((1 << 8) | ( 2 << 3) | 0)
#define	PI_VIP1_i_VD_2_					((1 << 8) | ( 2 << 3) | 1)
#define	PI_MCUSTOP_SDEX_2_				((1 << 8) | ( 2 << 3) | 2)
#define	PI_I2S2_I2SBCLK					((1 << 8) | ( 2 << 3) | 3)
#define	PI_GPIOB_GPIO_4_				((1 << 8) | ( 4 << 3) | 0)
#define	PI_VIP1_i_VD_3_					((1 << 8) | ( 4 << 3) | 1)
#define	PI_MCUSTOP_SDEX_3_				((1 << 8) | ( 4 << 3) | 2)
#define	PI_I2S2_I2SLRCLK				((1 << 8) | ( 4 << 3) | 3)
#define	PI_GPIOB_GPIO_6_				((1 << 8) | ( 6 << 3) | 0)
#define	PI_VIP1_i_VD_4_					((1 << 8) | ( 6 << 3) | 1)
#define	PI_MCUSTOP_SDEX_4_				((1 << 8) | ( 6 << 3) | 2)
#define	PI_I2S1_I2SSDO					((1 << 8) | ( 6 << 3) | 3)
#define	PI_GPIOB_GPIO_8_				((1 << 8) | ( 8 << 3) | 0)
#define	PI_VIP1_i_VD_5_					((1 << 8) | ( 8 << 3) | 1)
#define	PI_MCUSTOP_SDEX_5_				((1 << 8) | ( 8 << 3) | 2)
#define	PI_I2S2_I2SSDO					((1 << 8) | ( 8 << 3) | 3)
#define	PI_GPIOB_GPIO_9_				((1 << 8) | ( 9 << 3) | 0)
#define	PI_VIP1_i_VD_6_					((1 << 8) | ( 9 << 3) | 1)
#define	PI_MCUSTOP_SDEX_6_				((1 << 8) | ( 9 << 3) | 2)
#define	PI_I2S1_I2SSDI					((1 << 8) | ( 9 << 3) | 3)
#define	PI_GPIOB_GPIO_10_				((1 << 8) | (10 << 3) | 0)
#define	PI_VIP1_i_VD_7_					((1 << 8) | (10 << 3) | 1)
#define	PI_MCUSTOP_SDEX_7_				((1 << 8) | (10 << 3) | 2)
#define	PI_I2S2_I2SSDI					((1 << 8) | (10 << 3) | 3)
#define	PI_GPIOA_GPIO_29_				((0 << 8) | (29 << 3) | 0)
#define	PI_SDMMC0_SDMMC_CCLK				((0 << 8) | (29 << 3) | 1)
#define	PI_GPIOA_GPIO_31_				((0 << 8) | (31 << 3) | 0)
#define	PI_SDMMC0_SDMMC_CMD				((0 << 8) | (31 << 3) | 1)
#define	PI_GPIOB_GPIO_1_				((1 << 8) | ( 1 << 3) | 0)
#define	PI_SDMMC0_SDMMC_CDATA_0_			((1 << 8) | ( 1 << 3) | 1)
#define	PI_GPIOB_GPIO_3_				((1 << 8) | ( 3 << 3) | 0)
#define	PI_SDMMC0_SDMMC_CDATA_1_			((1 << 8) | ( 3 << 3) | 1)
#define	PI_GPIOB_GPIO_5_				((1 << 8) | ( 5 << 3) | 0)
#define	PI_SDMMC0_SDMMC_CDATA_2_			((1 << 8) | ( 5 << 3) | 1)
#define	PI_GPIOB_GPIO_7_				((1 << 8) | ( 7 << 3) | 0)
#define	PI_SDMMC0_SDMMC_CDATA_3_			((1 << 8) | ( 7 << 3) | 1)
#define	PI_MCUSTOP_CLE					((1 << 8) | (11 << 3) | 0)
#define	PI_MCUSTOP_CLE1					((1 << 8) | (11 << 3) | 1)
#define	PI_GPIOB_GPIO_11_				((1 << 8) | (11 << 3) | 2)
#define	PI_MCUSTOP_ALE					((1 << 8) | (12 << 3) | 0)
#define	PI_MCUSTOP_ALE1					((1 << 8) | (12 << 3) | 1)
#define	PI_GPIOB_GPIO_12_				((1 << 8) | (12 << 3) | 2)
#define	PI_MCUSTOP_SD_0_				((1 << 8) | (13 << 3) | 0)
#define	PI_GPIOB_GPIO_13_				((1 << 8) | (13 << 3) | 1)
#define	PI_MCUSTOP_RnB					((1 << 8) | (14 << 3) | 0)
#define	PI_MCUSTOP_RnB1					((1 << 8) | (14 << 3) | 1)
#define	PI_GPIOB_GPIO_14_				((1 << 8) | (14 << 3) | 2)
#define	PI_MCUSTOP_SD_1_				((1 << 8) | (15 << 3) | 0)
#define	PI_GPIOB_GPIO_15_				((1 << 8) | (15 << 3) | 1)
#define	PI_MCUSTOP_nNFOE				((1 << 8) | (16 << 3) | 0)
#define	PI_MCUSTOP_nNFOE1				((1 << 8) | (16 << 3) | 1)
#define	PI_GPIOB_GPIO_16_				((1 << 8) | (16 << 3) | 2)
#define	PI_MCUSTOP_SD_2_				((1 << 8) | (17 << 3) | 0)
#define	PI_GPIOB_GPIO_17_				((1 << 8) | (17 << 3) | 1)
#define	PI_MCUSTOP_nNFWE				((1 << 8) | (18 << 3) | 0)
#define	PI_MCUSTOP_nNFWE1				((1 << 8) | (18 << 3) | 1)
#define	PI_GPIOB_GPIO_18_				((1 << 8) | (18 << 3) | 2)
#define	PI_MCUSTOP_SD_3_				((1 << 8) | (19 << 3) | 0)
#define	PI_GPIOB_GPIO_19_				((1 << 8) | (19 << 3) | 1)
#define	PI_MCUSTOP_SD_4_				((1 << 8) | (20 << 3) | 0)
#define	PI_GPIOB_GPIO_20_				((1 << 8) | (20 << 3) | 1)
#define	PI_MCUSTOP_SD_5_				((1 << 8) | (21 << 3) | 0)
#define	PI_GPIOB_GPIO_21_				((1 << 8) | (21 << 3) | 1)
#define	PI_MCUSTOP_SD_6_				((1 << 8) | (22 << 3) | 0)
#define	PI_GPIOB_GPIO_22_				((1 << 8) | (22 << 3) | 1)
#define	PI_MCUSTOP_SD_7_				((1 << 8) | (23 << 3) | 0)
#define	PI_GPIOB_GPIO_23_				((1 << 8) | (23 << 3) | 1)
#define	PI_MCUSTOP_SD_8_				((1 << 8) | (24 << 3) | 0)
#define	PI_GPIOB_GPIO_24_				((1 << 8) | (24 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_0_				((1 << 8) | (24 << 3) | 2)
#define	PI_MCUSTOP_SD_9_				((1 << 8) | (25 << 3) | 0)
#define	PI_GPIOB_GPIO_25_				((1 << 8) | (25 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_1_				((1 << 8) | (25 << 3) | 2)
#define	PI_MCUSTOP_SD_10_				((1 << 8) | (26 << 3) | 0)
#define	PI_GPIOB_GPIO_26_				((1 << 8) | (26 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_2_				((1 << 8) | (26 << 3) | 2)
#define	PI_ECID_PAD_BONDING_ID_2_			((1 << 8) | (26 << 3) | 3)
#define	PI_MCUSTOP_SD_11_				((1 << 8) | (27 << 3) | 0)
#define	PI_GPIOB_GPIO_27_				((1 << 8) | (27 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_3_				((1 << 8) | (27 << 3) | 2)
#define	PI_MCUSTOP_SD_12_				((1 << 8) | (28 << 3) | 0)
#define	PI_GPIOB_GPIO_28_				((1 << 8) | (28 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_4_				((1 << 8) | (28 << 3) | 2)
#define	PI_pl01115_Uart_nodma1_UARTRXD			((1 << 8) | (28 << 3) | 3)
#define	PI_MCUSTOP_SD_13_				((1 << 8) | (29 << 3) | 0)
#define	PI_GPIOB_GPIO_29_				((1 << 8) | (29 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_5_				((1 << 8) | (29 << 3) | 2)
#define	PI_pl01115_Uart_nodma1_UARTTXD			((1 << 8) | (29 << 3) | 3)
#define	PI_MCUSTOP_SD_14_				((1 << 8) | (30 << 3) | 0)
#define	PI_GPIOB_GPIO_30_				((1 << 8) | (30 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_6_				((1 << 8) | (30 << 3) | 2)
#define	PI_pl01115_Uart_nodma2_UARTRXD			((1 << 8) | (30 << 3) | 3)
#define	PI_MCUSTOP_SD_15_				((1 << 8) | (31 << 3) | 0)
#define	PI_GPIOB_GPIO_31_				((1 << 8) | (31 << 3) | 1)
#define	PI_MPEGTSI_TDATA0_7_				((1 << 8) | (31 << 3) | 2)
#define	PI_pl01115_Uart_nodma2_UARTTXD			((1 << 8) | (31 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_0_				((2 << 8) | ( 0 << 3) | 0)
#define	PI_GPIOC_GPIO_0_				((2 << 8) | ( 0 << 3) | 1)
#define	PI_MCUSTOP_o_ADDR_1_				((2 << 8) | ( 1 << 3) | 0)
#define	PI_GPIOC_GPIO_1_				((2 << 8) | ( 1 << 3) | 1)
#define	PI_MCUSTOP_o_ADDR_2_				((2 << 8) | ( 2 << 3) | 0)
#define	PI_GPIOC_GPIO_2_				((2 << 8) | ( 2 << 3) | 1)
#define	PI_MCUSTOP_o_ADDR_3_				((2 << 8) | ( 3 << 3) | 0)
#define	PI_GPIOC_GPIO_3_				((2 << 8) | ( 3 << 3) | 1)
#define	PI_DISPLAYTOP_io_HDMI_CEC			((2 << 8) | ( 3 << 3) | 2)
#define	PI_SDMMC0_SDMMC_nRST				((2 << 8) | ( 3 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_4_				((2 << 8) | ( 4 << 3) | 0)
#define	PI_GPIOC_GPIO_4_				((2 << 8) | ( 4 << 3) | 1)
#define	PI_pl01115_Uart_modem_nUARTDCD			((2 << 8) | ( 4 << 3) | 2)
#define	PI_SDMMC0_SDMMC_CARD_nInt			((2 << 8) | ( 4 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_5_				((2 << 8) | ( 5 << 3) | 0)
#define	PI_GPIOC_GPIO_5_				((2 << 8) | ( 5 << 3) | 1)
#define	PI_pl01115_Uart_modem_nUARTCTS			((2 << 8) | ( 5 << 3) | 2)
#define	PI_SDMMC0_SDMMC_CARD_WritePrt			((2 << 8) | ( 5 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_6_				((2 << 8) | ( 6 << 3) | 0)
#define	PI_GPIOC_GPIO_6_				((2 << 8) | ( 6 << 3) | 1)
#define	PI_pl01115_Uart_modem_nUARTRTS			((2 << 8) | ( 6 << 3) | 2)
#define	PI_SDMMC0_SDMMC_CARD_nDetect			((2 << 8) | ( 6 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_7_				((2 << 8) | ( 7 << 3) | 0)
#define	PI_GPIOC_GPIO_7_				((2 << 8) | ( 7 << 3) | 1)
#define	PI_pl01115_Uart_modem_nUARTDSR			((2 << 8) | ( 7 << 3) | 2)
#define	PI_SDMMC1_SDMMC_nRST				((2 << 8) | ( 7 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_8_				((2 << 8) | ( 8 << 3) | 0)
#define	PI_GPIOC_GPIO_8_				((2 << 8) | ( 8 << 3) | 1)
#define	PI_pl01115_Uart_modem_nUARTDTR			((2 << 8) | ( 8 << 3) | 2)
#define	PI_SDMMC1_SDMMC_CARD_nInt			((2 << 8) | ( 8 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_9_				((2 << 8) | ( 9 << 3) | 0)
#define	PI_GPIOC_GPIO_9_				((2 << 8) | ( 9 << 3) | 1)
#define	PI_SSP2_SSPCLK_IO				((2 << 8) | ( 9 << 3) | 2)
#define	PI_PDM_o_Strobe					((2 << 8) | ( 9 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_10_				((2 << 8) | (10 << 3) | 0)
#define	PI_GPIOC_GPIO_10_				((2 << 8) | (10 << 3) | 1)
#define	PI_SSP2_SSPFSS					((2 << 8) | (10 << 3) | 2)
#define	PI_MCUSTOP_nNCS_2_				((2 << 8) | (10 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_11_				((2 << 8) | (11 << 3) | 0)
#define	PI_GPIOC_GPIO_11_				((2 << 8) | (11 << 3) | 1)
#define	PI_SSP2_SSPRXD					((2 << 8) | (11 << 3) | 2)
#define	PI_USB20OTG_o_DrvVBUS				((2 << 8) | (11 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_12_				((2 << 8) | (12 << 3) | 0)
#define	PI_GPIOC_GPIO_12_				((2 << 8) | (12 << 3) | 1)
#define	PI_SSP2_SSPTXD					((2 << 8) | (12 << 3) | 2)
#define	PI_SDMMC2_SDMMC_nRST				((2 << 8) | (12 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_13_				((2 << 8) | (13 << 3) | 0)
#define	PI_GPIOC_GPIO_13_				((2 << 8) | (13 << 3) | 1)
#define	PI_PWM_TOUT1					((2 << 8) | (13 << 3) | 2)
#define	PI_SDMMC2_SDMMC_CARD_nInt			((2 << 8) | (13 << 3) | 3)
#define	PI_GPIOD_GPIO_18_				((3 << 8) | (18 << 3) | 0)
#define	PI_UART0_UARTTXD				((3 << 8) | (18 << 3) | 1)
#define	PI_pl01115_Uart_nodma0_SMCAYEN			((3 << 8) | (18 << 3) | 2)
#define	PI_SDMMC2_SDMMC_CARD_WritePrt			((3 << 8) | (18 << 3) | 3)
#define	PI_GPIOD_GPIO_19_				((3 << 8) | (19 << 3) | 0)
#define	PI_pl01115_Uart_modem_UARTTXD			((3 << 8) | (19 << 3) | 1)
#define	PI_UART0_SMCAYEN				((3 << 8) | (19 << 3) | 2)
#define	PI_SDMMC2_SDMMC_CARD_nDetect			((3 << 8) | (19 << 3) | 3)
#define	PI_GPIOD_GPIO_20_				((3 << 8) | (20 << 3) | 0)
#define	PI_UART1_UARTTXD				((3 << 8) | (20 << 3) | 1)
#define	PI_CAN0_o_TX					((3 << 8) | (20 << 3) | 2)
#define	PI_SDMMC1_SDMMC_CARD_WritePrt			((3 << 8) | (20 << 3) | 3)
#define	PI_GPIOD_GPIO_21_				((3 << 8) | (21 << 3) | 0)
#define	PI_pl01115_Uart_nodma0_UARTTXD			((3 << 8) | (21 << 3) | 1)
#define	PI_CAN1_o_TX					((3 << 8) | (21 << 3) | 2)
#define	PI_SDMMC1_SDMMC_CARD_nDetect			((3 << 8) | (21 << 3) | 3)
#define	PI_GPIOD_GPIO_22_				((3 << 8) | (22 << 3) | 0)
#define	PI_SDMMC1_SDMMC_CCLK				((3 << 8) | (22 << 3) | 1)
#define	PI_GPIOD_GPIO_23_				((3 << 8) | (23 << 3) | 0)
#define	PI_SDMMC1_SDMMC_CMD				((3 << 8) | (23 << 3) | 1)
#define	PI_GPIOD_GPIO_24_				((3 << 8) | (24 << 3) | 0)
#define	PI_SDMMC1_SDMMC_CDATA_0_			((3 << 8) | (24 << 3) | 1)
#define	PI_GPIOD_GPIO_25_				((3 << 8) | (25 << 3) | 0)
#define	PI_SDMMC1_SDMMC_CDATA_1_			((3 << 8) | (25 << 3) | 1)
#define	PI_GPIOD_GPIO_26_				((3 << 8) | (26 << 3) | 0)
#define	PI_SDMMC1_SDMMC_CDATA_2_			((3 << 8) | (26 << 3) | 1)
#define	PI_GPIOD_GPIO_27_				((3 << 8) | (27 << 3) | 0)
#define	PI_SDMMC1_SDMMC_CDATA_3_			((3 << 8) | (27 << 3) | 1)
#define	PI_MCUSTOP_nSWAIT				((2 << 8) | (25 << 3) | 0)
#define	PI_GPIOC_GPIO_25_				((2 << 8) | (25 << 3) | 1)
#define	PI_SPDIFTX_SPDIF_DATA				((2 << 8) | (25 << 3) | 2)
#define	PI_MCUSTOP_nSOE					((4 << 8) | (30 << 3) | 0)
#define	PI_GPIOE_GPIO_30_				((4 << 8) | (30 << 3) | 1)
#define	PI_MCUSTOP_nSWE					((4 << 8) | (31 << 3) | 0)
#define	PI_GPIOE_GPIO_31_				((4 << 8) | (31 << 3) | 1)
#define	PI_MCUSTOP_RDnWR				((2 << 8) | (26 << 3) | 0)
#define	PI_GPIOC_GPIO_26_				((2 << 8) | (26 << 3) | 1)
#define	PI_PDM_i_Data0					((2 << 8) | (26 << 3) | 2)
#define	PI_MCUSTOP_nSDQM1				((2 << 8) | (27 << 3) | 0)
#define	PI_GPIOC_GPIO_27_				((2 << 8) | (27 << 3) | 1)
#define	PI_PDM_i_Data1					((2 << 8) | (27 << 3) | 2)
#define	PI_GPIOC_GPIO_28_				((2 << 8) | (28 << 3) | 0)
#define	PI_MCUSTOP_nSCS_1_				((2 << 8) | (28 << 3) | 1)
#define	PI_pl01115_Uart_modem_nUARTRI			((2 << 8) | (28 << 3) | 2)
#define	PI_GPIOC_GPIO_29_				((2 << 8) | (29 << 3) | 0)
#define	PI_SSP0_SSPCLK_IO				((2 << 8) | (29 << 3) | 1)
#define	PI_GPIOC_GPIO_30_				((2 << 8) | (30 << 3) | 0)
#define	PI_SSP0_SSPFSS					((2 << 8) | (30 << 3) | 1)
#define	PI_GPIOC_GPIO_31_				((2 << 8) | (31 << 3) | 0)
#define	PI_SSP0_SSPTXD					((2 << 8) | (31 << 3) | 1)
#define	PI_GPIOD_GPIO_0_				((3 << 8) | ( 0 << 3) | 0)
#define	PI_SSP0_SSPRXD					((3 << 8) | ( 0 << 3) | 1)
#define	PI_PWM_TOUT3					((3 << 8) | ( 0 << 3) | 2)
#define	PI_GPIOD_GPIO_1_				((3 << 8) | ( 1 << 3) | 0)
#define	PI_PWM_TOUT0					((3 << 8) | ( 1 << 3) | 1)
#define	PI_MCUSTOP_o_ADDR_25_				((3 << 8) | ( 1 << 3) | 2)
#define	PI_GPIOD_GPIO_2_				((3 << 8) | ( 2 << 3) | 0)
#define	PI_I2C0_SCL					((3 << 8) | ( 2 << 3) | 1)
#define	PI_pl01115_Uart_nodma1_SMCAYEN			((3 << 8) | ( 2 << 3) | 2)
#define	PI_GPIOD_GPIO_3_				((3 << 8) | ( 3 << 3) | 0)
#define	PI_I2C0_SDA					((3 << 8) | ( 3 << 3) | 1)
#define	PI_pl01115_Uart_nodma2_SMCAYEN			((3 << 8) | ( 3 << 3) | 2)
#define	PI_GPIOD_GPIO_4_				((3 << 8) | ( 4 << 3) | 0)
#define	PI_I2C1_SCL					((3 << 8) | ( 4 << 3) | 1)
#define	PI_GPIOD_GPIO_5_				((3 << 8) | ( 5 << 3) | 0)
#define	PI_I2C1_SDA					((3 << 8) | ( 5 << 3) | 1)
#define	PI_GPIOD_GPIO_6_				((3 << 8) | ( 6 << 3) | 0)
#define	PI_I2C2_SCL					((3 << 8) | ( 6 << 3) | 1)
#define	PI_GPIOD_GPIO_7_				((3 << 8) | ( 7 << 3) | 0)
#define	PI_I2C2_SDA					((3 << 8) | ( 7 << 3) | 1)
#define	PI_GPIOD_GPIO_8_				((3 << 8) | ( 8 << 3) | 0)
#define	PI_PPM_i_PPMIn					((3 << 8) | ( 8 << 3) | 1)
#define	PI_GPIOD_GPIO_9_				((3 << 8) | ( 9 << 3) | 0)
#define	PI_I2S0_I2SSDO					((3 << 8) | ( 9 << 3) | 1)
#define	PI_AC97_ACSDATAOUT				((3 << 8) | ( 9 << 3) | 2)
#define	PI_GPIOD_GPIO_10_				((3 << 8) | (10 << 3) | 0)
#define	PI_I2S0_I2SBCLK					((3 << 8) | (10 << 3) | 1)
#define	PI_AC97_ACBITCLK				((3 << 8) | (10 << 3) | 2)
#define	PI_GPIOD_GPIO_11_				((3 << 8) | (11 << 3) | 0)
#define	PI_I2S0_I2SSDI					((3 << 8) | (11 << 3) | 1)
#define	PI_AC97_ACSDATAIN				((3 << 8) | (11 << 3) | 2)
#define	PI_GPIOD_GPIO_12_				((3 << 8) | (12 << 3) | 0)
#define	PI_I2S0_I2SLRCLK				((3 << 8) | (12 << 3) | 1)
#define	PI_AC97_ACSYNC					((3 << 8) | (12 << 3) | 2)
#define	PI_GPIOD_GPIO_13_				((3 << 8) | (13 << 3) | 0)
#define	PI_I2S0_I2SCODCLK				((3 << 8) | (13 << 3) | 1)
#define	PI_AC97_nACRESET				((3 << 8) | (13 << 3) | 2)
#define	PI_GPIOD_GPIO_14_				((3 << 8) | (14 << 3) | 0)
#define	PI_UART0_UARTRXD				((3 << 8) | (14 << 3) | 1)
#define	PI_pl01115_Uart_modem_SMCAYEN			((3 << 8) | (14 << 3) | 2)
#define	PI_GPIOD_GPIO_15_				((3 << 8) | (15 << 3) | 0)
#define	PI_pl01115_Uart_modem_UARTRXD			((3 << 8) | (15 << 3) | 1)
#define	PI_UART1_SMCAYEN				((3 << 8) | (15 << 3) | 2)
#define	PI_GPIOD_GPIO_16_				((3 << 8) | (16 << 3) | 0)
#define	PI_UART1_UARTRXD				((3 << 8) | (16 << 3) | 1)
#define	PI_CAN0_i_RX					((3 << 8) | (16 << 3) | 2)
#define	PI_GPIOD_GPIO_17_				((3 << 8) | (17 << 3) | 0)
#define	PI_pl01115_Uart_nodma0_UARTRXD			((3 << 8) | (17 << 3) | 1)
#define	PI_CAN1_i_RX					((3 << 8) | (17 << 3) | 2)
#define	PI_MCUSTOP_o_ADDR_14_				((2 << 8) | (14 << 3) | 0)
#define	PI_GPIOC_GPIO_14_				((2 << 8) | (14 << 3) | 1)
#define	PI_PWM_TOUT2					((2 << 8) | (14 << 3) | 2)
#define	PI_VIP1_i_ExtCLK2				((2 << 8) | (14 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_15_				((2 << 8) | (15 << 3) | 0)
#define	PI_GPIOC_GPIO_15_				((2 << 8) | (15 << 3) | 1)
#define	PI_MPEGTSI_TSCLK0				((2 << 8) | (15 << 3) | 2)
#define	PI_VIP1_i_ExtHSYNC2				((2 << 8) | (15 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_16_				((2 << 8) | (16 << 3) | 0)
#define	PI_GPIOC_GPIO_16_				((2 << 8) | (16 << 3) | 1)
#define	PI_MPEGTSI_TSYNC0				((2 << 8) | (16 << 3) | 2)
#define	PI_VIP1_i_ExtVSYNC2				((2 << 8) | (16 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_17_				((2 << 8) | (17 << 3) | 0)
#define	PI_GPIOC_GPIO_17_				((2 << 8) | (17 << 3) | 1)
#define	PI_MPEGTSI_TDP0					((2 << 8) | (17 << 3) | 2)
#define	PI_VIP1_i_VD2_0_				((2 << 8) | (17 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_18_				((2 << 8) | (18 << 3) | 0)
#define	PI_GPIOC_GPIO_18_				((2 << 8) | (18 << 3) | 1)
#define	PI_SDMMC2_SDMMC_CCLK				((2 << 8) | (18 << 3) | 2)
#define	PI_VIP1_i_VD2_1_				((2 << 8) | (18 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_19_				((2 << 8) | (19 << 3) | 0)
#define	PI_GPIOC_GPIO_19_				((2 << 8) | (19 << 3) | 1)
#define	PI_SDMMC2_SDMMC_CMD				((2 << 8) | (19 << 3) | 2)
#define	PI_VIP1_i_VD2_2_				((2 << 8) | (19 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_20_				((2 << 8) | (20 << 3) | 0)
#define	PI_GPIOC_GPIO_20_				((2 << 8) | (20 << 3) | 1)
#define	PI_SDMMC2_SDMMC_CDATA_0_			((2 << 8) | (20 << 3) | 2)
#define	PI_VIP1_i_VD2_3_				((2 << 8) | (20 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_21_				((2 << 8) | (21 << 3) | 0)
#define	PI_GPIOC_GPIO_21_				((2 << 8) | (21 << 3) | 1)
#define	PI_SDMMC2_SDMMC_CDATA_1_			((2 << 8) | (21 << 3) | 2)
#define	PI_VIP1_i_VD2_4_				((2 << 8) | (21 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_22_				((2 << 8) | (22 << 3) | 0)
#define	PI_GPIOC_GPIO_22_				((2 << 8) | (22 << 3) | 1)
#define	PI_SDMMC2_SDMMC_CDATA_2_			((2 << 8) | (22 << 3) | 2)
#define	PI_VIP1_i_VD2_5_				((2 << 8) | (22 << 3) | 3)
#define	PI_MCUSTOP_o_ADDR_23_				((2 << 8) | (23 << 3) | 0)
#define	PI_GPIOC_GPIO_23_				((2 << 8) | (23 << 3) | 1)
#define	PI_SDMMC2_SDMMC_CDATA_3_			((2 << 8) | (23 << 3) | 2)
#define	PI_VIP1_i_VD2_6_				((2 << 8) | (23 << 3) | 3)
#define	PI_MCUSTOP_LATADDR				((2 << 8) | (24 << 3) | 0)
#define	PI_GPIOC_GPIO_24_				((2 << 8) | (24 << 3) | 1)
#define	PI_SPDIFRX_SPDIFIN				((2 << 8) | (24 << 3) | 2)
#define	PI_VIP1_i_VD2_7_				((2 << 8) | (24 << 3) | 3)
#define	PI_GPIOD_GPIO_28_				((3 << 8) | (28 << 3) | 0)
#define	PI_VIP0_i_VD_0_					((3 << 8) | (28 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_0_				((3 << 8) | (28 << 3) | 2)
#define	PI_MCUSTOP_o_ADDR_24_				((3 << 8) | (28 << 3) | 3)
#define	PI_GPIOD_GPIO_29_				((3 << 8) | (29 << 3) | 0)
#define	PI_VIP0_i_VD_1_					((3 << 8) | (29 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_1_				((3 << 8) | (29 << 3) | 2)
#define	PI_GPIOD_GPIO_30_				((3 << 8) | (30 << 3) | 0)
#define	PI_VIP0_i_VD_2_					((3 << 8) | (30 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_2_				((3 << 8) | (30 << 3) | 2)
#define	PI_GPIOD_GPIO_31_				((3 << 8) | (31 << 3) | 0)
#define	PI_VIP0_i_VD_3_					((3 << 8) | (31 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_3_				((3 << 8) | (31 << 3) | 2)
#define	PI_GPIOE_GPIO_0_				((4 << 8) | ( 0 << 3) | 0)
#define	PI_VIP0_i_VD_4_					((4 << 8) | ( 0 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_4_				((4 << 8) | ( 0 << 3) | 2)
#define	PI_GPIOE_GPIO_1_				((4 << 8) | ( 1 << 3) | 0)
#define	PI_VIP0_i_VD_5_					((4 << 8) | ( 1 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_5_				((4 << 8) | ( 1 << 3) | 2)
#define	PI_GPIOE_GPIO_2_				((4 << 8) | ( 2 << 3) | 0)
#define	PI_VIP0_i_VD_6_					((4 << 8) | ( 2 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_6_				((4 << 8) | ( 2 << 3) | 2)
#define	PI_GPIOE_GPIO_3_				((4 << 8) | ( 3 << 3) | 0)
#define	PI_VIP0_i_VD_7_					((4 << 8) | ( 3 << 3) | 1)
#define	PI_MPEGTSI_TDATA1_7_				((4 << 8) | ( 3 << 3) | 2)
#define	PI_GPIOE_GPIO_4_				((4 << 8) | ( 4 << 3) | 0)
#define	PI_VIP0_i_ExtCLK				((4 << 8) | ( 4 << 3) | 1)
#define	PI_MPEGTSI_TSCLK1				((4 << 8) | ( 4 << 3) | 2)
#define	PI_GPIOE_GPIO_5_				((4 << 8) | ( 5 << 3) | 0)
#define	PI_VIP0_i_ExtHSYNC				((4 << 8) | ( 5 << 3) | 1)
#define	PI_MPEGTSI_TSYNC1				((4 << 8) | ( 5 << 3) | 2)
#define	PI_GPIOE_GPIO_6_				((4 << 8) | ( 6 << 3) | 0)
#define	PI_VIP0_i_ExtVSYNC				((4 << 8) | ( 6 << 3) | 1)
#define	PI_MPEGTSI_TDP1					((4 << 8) | ( 6 << 3) | 2)
#define	PI_nx01301_CORTEXA9MP_TOP_QUADL2C_nTRST		((4 << 8) | (25 << 3) | 0)
#define	PI_GPIOE_GPIO_25_				((4 << 8) | (25 << 3) | 1)
#define	PI_nx01301_CORTEXA9MP_TOP_QUADL2C_TMS		((4 << 8) | (26 << 3) | 0)
#define	PI_GPIOE_GPIO_26_				((4 << 8) | (26 << 3) | 1)
#define	PI_nx01301_CORTEXA9MP_TOP_QUADL2C_TDI		((4 << 8) | (27 << 3) | 0)
#define	PI_GPIOE_GPIO_27_				((4 << 8) | (27 << 3) | 1)
#define	PI_nx01301_CORTEXA9MP_TOP_QUADL2C_TCLK		((4 << 8) | (28 << 3) | 0)
#define	PI_GPIOE_GPIO_28_				((4 << 8) | (28 << 3) | 1)
#define	PI_nx01301_CORTEXA9MP_TOP_QUADL2C_TDO		((4 << 8) | (29 << 3) | 0)
#define	PI_GPIOE_GPIO_29_				((4 << 8) | (29 << 3) | 1)
#define	PI_GPIOE_GPIO_7_				((4 << 8) | ( 7 << 3) | 0)
#define	PI_DWC_GMAC_PHY_TXD_0_				((4 << 8) | ( 7 << 3) | 1)
#define	PI_VIP1_i_ExtVSYNC				((4 << 8) | ( 7 << 3) | 2)
#define	PI_GPIOE_GPIO_8_				((4 << 8) | ( 8 << 3) | 0)
#define	PI_DWC_GMAC_PHY_TXD_1_				((4 << 8) | ( 8 << 3) | 1)
#define	PI_GPIOE_GPIO_9_				((4 << 8) | ( 9 << 3) | 0)
#define	PI_DWC_GMAC_PHY_TXD_2_				((4 << 8) | ( 9 << 3) | 1)
#define	PI_GPIOE_GPIO_10_				((4 << 8) | (10 << 3) | 0)
#define	PI_DWC_GMAC_PHY_TXD_3_				((4 << 8) | (10 << 3) | 1)
#define	PI_GPIOE_GPIO_11_				((4 << 8) | (11 << 3) | 0)
#define	PI_DWC_GMAC_PHY_TXEN				((4 << 8) | (11 << 3) | 1)
#define	PI_GPIOE_GPIO_12_				((4 << 8) | (12 << 3) | 0)
#define	PI_DWC_GMAC_PHY_TXER				((4 << 8) | (12 << 3) | 1)
#define	PI_GPIOE_GPIO_13_				((4 << 8) | (13 << 3) | 0)
#define	PI_DWC_GMAC_PHY_COL				((4 << 8) | (13 << 3) | 1)
#define	PI_VIP1_i_ExtHSYNC				((4 << 8) | (13 << 3) | 2)
#define	PI_GPIOE_GPIO_14_				((4 << 8) | (14 << 3) | 0)
#define	PI_DWC_GMAC_PHY_RXD_0_				((4 << 8) | (14 << 3) | 1)
#define	PI_SSP1_SSPCLK_IO				((4 << 8) | (14 << 3) | 2)
#define	PI_GPIOE_GPIO_15_				((4 << 8) | (15 << 3) | 0)
#define	PI_DWC_GMAC_PHY_RXD_1_				((4 << 8) | (15 << 3) | 1)
#define	PI_SSP1_SSPFSS					((4 << 8) | (15 << 3) | 2)
#define	PI_GPIOE_GPIO_16_				((4 << 8) | (16 << 3) | 0)
#define	PI_DWC_GMAC_PHY_RXD_2_				((4 << 8) | (16 << 3) | 1)
#define	PI_GPIOE_GPIO_17_				((4 << 8) | (17 << 3) | 0)
#define	PI_DWC_GMAC_PHY_RXD_3_				((4 << 8) | (17 << 3) | 1)
#define	PI_GPIOE_GPIO_18_				((4 << 8) | (18 << 3) | 0)
#define	PI_DWC_GMAC_CLK_RX				((4 << 8) | (18 << 3) | 1)
#define	PI_SSP1_SSPRXD					((4 << 8) | (18 << 3) | 2)
#define	PI_GPIOE_GPIO_19_				((4 << 8) | (19 << 3) | 0)
#define	PI_DWC_GMAC_PHY_RXDV				((4 << 8) | (19 << 3) | 1)
#define	PI_SSP1_SSPTXD					((4 << 8) | (19 << 3) | 2)
#define	PI_GPIOE_GPIO_20_				((4 << 8) | (20 << 3) | 0)
#define	PI_DWC_GMAC_GMII_MDC				((4 << 8) | (20 << 3) | 1)
#define	PI_GPIOE_GPIO_21_				((4 << 8) | (21 << 3) | 0)
#define	PI_DWC_GMAC_GMII_MDI				((4 << 8) | (21 << 3) | 1)
#define	PI_GPIOE_GPIO_22_				((4 << 8) | (22 << 3) | 0)
#define	PI_DWC_GMAC_PHY_RXER				((4 << 8) | (22 << 3) | 1)
#define	PI_GPIOE_GPIO_23_				((4 << 8) | (23 << 3) | 0)
#define	PI_DWC_GMAC_PHY_CRS				((4 << 8) | (23 << 3) | 1)
#define	PI_GPIOE_GPIO_24_				((4 << 8) | (24 << 3) | 0)
#define	PI_DWC_GMAC_GTX_CLK				((4 << 8) | (24 << 3) | 1)

#endif // __NX_CHIP_P4330_H__
