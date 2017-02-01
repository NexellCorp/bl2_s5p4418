/*
 * Copyright (C) 2016  Nexell Co., Ltd.
 * Author: Sangjong, Han <hans@nexell.co.kr>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "nx_pyrope.h"
#include "cfgBootDefine.h"

        .align
/* Start and e.nd of BSS */

.globl __bss_start__
.globl __bss_end__

/*
 * entry point of main function
 */
.global BootMain
.text
//==================================================================
// vectors
//==================================================================
.global startup
startup:
	mov	r4, #0
	mcr     p15, 0, r4, c7, c5, 0 //; invalidate all instruction caches

	mrc	p15, 0, r12, c0, c0, 5         	// Get our cpu id
	ands	r12, r12, #0xF			// Save CPU id
	bne	.

	/* Set to zero, Clear SRAM */
	ldr	r1, =__bss_start__		// this is auto-relocated!
	ldr	r2, =__bss_end__		// this is auto-relocated!

	mov	r3, #0x00000000			// prepare zero to clear BSS

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

.global call_monitor
call_monitor:
	mov	r0, #4
	smc	#12345
	b	.

	.ltorg
