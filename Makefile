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

include config.mak

LDFLAGS		=	-Bstatic						\
			-Wl,-Map=$(DIR_TARGETOUTPUT)/$(TARGET_NAME).map,--cref	\
			-T$(LDS_NAME).lds					\
			-Wl,--start-group					\
			-Lsrc/$(DIR_OBJOUTPUT)					\
			-Wl,--end-group						\
			-Wl,--build-id=none					\
			-nostdlib

SYS_OBJS	+=	startup.o armv7_libs.o bl2.o		\
			resetcon.o GPIO.o debug.o util.o	\
			buildinfo.o printf.o util_arm.o


SYS_OBJS	+=	CRYPTO.o

SYS_OBJS	+=	sha256.o rsa_verify_pss.o bignum.o


ifeq ($(SUPPORT_USB_BOOT),y)
CFLAGS		+=	-DSUPPORT_USB_BOOT
SYS_OBJS	+=	iUSBBOOT.o
endif

ifeq ($(SUPPORT_SDMMC_BOOT),y)
CFLAGS		+=	-DSUPPORT_SDMMC_BOOT
SYS_OBJS	+=	iSDHCBOOT.o
endif


SYS_OBJS_LIST	=	$(addprefix $(DIR_OBJOUTPUT)/,$(SYS_OBJS))

SYS_INCLUDES	=	-I src

################################################################################
$(DIR_OBJOUTPUT)/%.o: src/%.c
	@echo [compile....$<]
	$(Q)$(CC) -MMD $< -c -o $@ $(CFLAGS) $(SYS_INCLUDES)
################################################################################
$(DIR_OBJOUTPUT)/%.o: src/%.S
	@echo [compile....$<]
	$(Q)$(CC) -MMD $< -c -o $@ $(ASFLAG) $(CFLAGS) $(SYS_INCLUDES)
################################################################################

all: mkobjdir startup $(SYS_OBJS_LIST) link bin

mkobjdir:
ifeq ($(OS),Windows_NT)
	@if not exist $(DIR_OBJOUTPUT)			\
		@$(MKDIR) $(DIR_OBJOUTPUT)
	@if not exist $(DIR_TARGETOUTPUT)		\
		@$(MKDIR) $(DIR_TARGETOUTPUT)
else
	@if	[ ! -e $(DIR_OBJOUTPUT) ]; then 	\
		$(MKDIR) $(DIR_OBJOUTPUT);		\
	fi;
	@if	[ ! -e $(DIR_TARGETOUTPUT) ]; then 	\
		$(MKDIR) $(DIR_TARGETOUTPUT);		\
	fi;
endif

startup:
	@echo [compile....startup.S]
	$(Q)$(CC) -MMD src/startup.S -c -o $@ $(ASFLAG) $(CFLAGS) $(SYS_INCLUDES)

link: $(SYS_OBJS_LIST)
	@echo [link.... $(DIR_TARGETOUTPUT)/$(TARGET_NAME).elf]

	$(Q)$(CC) $(SYS_OBJS_LIST) $(LDFLAGS)	\
		-o $(DIR_TARGETOUTPUT)/$(TARGET_NAME).elf

bin: link
	@echo [binary.... $(DIR_TARGETOUTPUT)/$(TARGET_NAME).bin]
	$(Q)$(MAKEBIN) -O binary $(DIR_TARGETOUTPUT)/$(TARGET_NAME).elf	\
		$(DIR_TARGETOUTPUT)/$(TARGET_NAME).bin
ifeq ($(OS),Windows_NT)
	@if exist $(DIR_OBJOUTPUT)			\
		@$(RM) $(DIR_OBJOUTPUT)\buildinfo.o
else
	@if	[ -e $(DIR_OBJOUTPUT) ]; then 		\
		$(RM) $(DIR_OBJOUTPUT)/buildinfo.o;	\
	fi;
endif

################################################################################
clean:
ifeq ($(OS),Windows_NT)
	@if exist $(DIR_OBJOUTPUT)			\
		@$(RMDIR) $(DIR_OBJOUTPUT)
	@if exist $(DIR_TARGETOUTPUT)			\
		@$(RMDIR) $(DIR_TARGETOUTPUT)
else
	@if	[ -e $(DIR_OBJOUTPUT) ]; then 		\
		$(RMDIR) $(DIR_OBJOUTPUT);		\
	fi;
	@if	[ -e $(DIR_TARGETOUTPUT) ]; then 	\
		$(RMDIR) $(DIR_TARGETOUTPUT);		\
	fi;
endif

-include $(SYS_OBJS_LIST:.o=.d)
