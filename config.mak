 # Copyright (C) 2016  Nexell Co., Ltd.
 # Author: Sangjong, Han <hans@nexell.co.kr>
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
 #
 # as published by the Free Software Foundation; either version 2
 # of the License, or (at your option) any later version.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 #
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
CROSS_TOOL_TOP		=
CROSS_TOOL		= $(CROSS_TOOL_TOP)arm-none-eabi-
else
CROSS_TOOL_TOP		=
CROSS_TOOL		= $(CROSS_TOOL_TOP)arm-eabi-
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
CC			= $(CROSS_TOOL)gcc
LD 			= $(CROSS_TOOL)ld
AS 			= $(CROSS_TOOL)as
AR 			= $(CROSS_TOOL)ar
MAKEBIN			= $(CROSS_TOOL)objcopy
OBJCOPY			= $(CROSS_TOOL)objcopy
RANLIB 			= $(CROSS_TOOL)ranlib

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
