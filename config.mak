#
# Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
# Nexell Co. Proprietary & Confidential
#
# Nexell informs that this code and information is provided "as is" base
# and without warranty of any kind, either expressed or implied, including
# but not limited to the implied warranties of merchantability and/or
# fitness for a particular puporse.
#
#	Module		:
#	File		:
#	Description	:
#	Author		: Hans
#	History		: 2017.02.28 new release

###########################################################################
# Build Version info
###########################################################################
VERINFO			= V001

###########################################################################
# Build Environment
###########################################################################
CHIPNAME		= S5P4418

DEBUG			= n

CRC_CHECK		= n

CFLAGS			:=

SUPPORT_USB_BOOT	= y
SUPPORT_SDMMC_BOOT	= y

# Secure Boot
SECURE_ON		?= 0
SECURE			?= NO

# cross-tool pre-header
ifeq ($(OS),Windows_NT)
CROSS_COMPILE_TOP	?=
CROSS_COMPILE		?= $(CROSS_COMPILE_TOP)arm-none-eabi-
else
CROSS_COMPILE_TOP	?=
CROSS_COMPILE		?= $(CROSS_COMPILE_TOP)arm-eabi-
endif

###########################################################################
# Top Names
###########################################################################
PROJECT_NAME		= $(CHIPNAME)_bl2_$(VERINFO)
TARGET_NAME		= pyrope-bl2
LDS_NAME		= pyrope_bl2

###########################################################################
# Directories
###########################################################################
DIR_PROJECT_TOP		=

DIR_OBJOUTPUT		= obj
DIR_TARGETOUTPUT	= out

CODE_MAIN_INCLUDE	=

###########################################################################
# Build Environment
###########################################################################
CPU			= cortex-a9
CC			= $(CROSS_COMPILE)gcc
LD 			= $(CROSS_COMPILE)ld
AS 			= $(CROSS_COMPILE)as
AR 			= $(CROSS_COMPILE)ar
MAKEBIN			= $(CROSS_COMPILE)objcopy
OBJCOPY			= $(CROSS_COMPILE)objcopy
RANLIB 			= $(CROSS_COMPILE)ranlib

GCC_LIB			= $(shell $(CC) -print-libgcc-file-name)

ifeq ($(SECURE_ON), 1)
CFLAGS			+=  -DSECURE_ON
endif

ifeq ($(DEBUG), y)
CFLAGS			+= -DNX_DEBUG -O0
Q			=
else
CFLAGS			+= -DNX_RELEASE -Os
Q			= @
endif

###########################################################################
# MISC tools for MS-DOS
###########################################################################
ifeq ($(OS),Windows_NT)
MKDIR			= mkdir
RM			= del /q /F
MV			= move
CD			= cd
CP			= copy
ECHO			= echo
RMDIR			= rmdir /S /Q
else
MKDIR			= mkdir
RM			= rm -f
MV			= mv
CD			= cd
CP			= cp
ECHO			= echo
RMDIR			= rm -rf
endif
###########################################################################
# FLAGS
###########################################################################
ARFLAGS			= rcs
ARFLAGS_REMOVE		= -d
ARLIBFLAGS		= -v -s

ASFLAG			= -D__ASSEMBLY__

CFLAGS			+=	-g -Wall				\
				-Wextra -ffreestanding -fno-builtin	\
				-msoft-float				\
				-mlittle-endian				\
				-mcpu=$(CPU)				\
				-mstructure-size-boundary=32		\
				$(CODE_MAIN_INCLUDE)			\
				-D__arm -DLOAD_FROM_$(BOOTFROM)		\
				-DCHIPID_$(CHIPNAME)			\
				-D_2NDBOOT_MODE

ifeq ($(SECURE), YES)
CFLAGS			+=	-DSECURE_MODE
endif


ifeq ($(CRC_CHECK), y)
CHECKSUM		+=	CRC_CHECK
CFLAGS			+=	-D$(CHECKSUM)_ON
endif

ifeq ($(QUICKBOOT), 1)
CFLAGS += -DQUICKBOOT
endif
