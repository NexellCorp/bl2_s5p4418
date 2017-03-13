/*
 * Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
 * Nexell Co. Proprietary & Confidential
 *
 * Nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular puporse.
 * This code is not allowed to be redelivered or released to the public
 * without permission.
 * 
 * Module	:
 * File		:
 * Description	:
 * Author	: Hans
 * History	: 2017.02.28 new release
 */
#include "nx_pyrope.h"

.global BootMain
/* Start and end of BSS */
.global __bss_start__
.global __bss_end__

/*
 * entry point of main function
 */
        .align
.text
.global startup
startup:
//	r0: is resume
	mov	r4, #0
	mcr	p15, 0, r4, c7, c5, 0 //; invalidate all instruction caches

	mrc	p15, 0, r12, c0, c0, 5         	// Get our cpu id
	ands	r12, r12, #0xF			// Save CPU id
	bne	.

	/* Set to zero, Clear SRAM */
	ldr	r1, =__bss_start__		// this is auto-relocated!
	ldr	r2, =__bss_end__		// this is auto-relocated!

	mov	r3, #0				// prepare zero to clear BSS

clbss_l:
	cmp	r1, r2				// while not at end of BSS
	strlo	r3, [r1]			// clear 32-bit BSS word
	addlo	r1, r1, #4			// move to next
	blo	clbss_l

main:
	/* Set stack pointer */
	ldr	sp, =BASEADDR_SECUREMEM
	add	sp, sp, #SECUREMEM_SIZE

	ldr	r1, =startup
	and	r1, #0xffff00ff

	bl	BootMain

spinwfi:
	wfi
	b	spinwfi

// r0: warm or coldboot
// r1: secure os Start
// lr: non-secure bootloader
.global launch
// void	launch(isresume, secure, non-secure, dispatcher);
launch:
	mov	r4, #0
	mcr     p15, 0, r4, c7, c5, 0 //; invalidate all instruction caches
	mcr     p15, 0, r4, c7, c5, 6 //; invalidate branch prediction
	mov	lr, r2
	bx	r3
	wfi
	b	.

	.ltorg
