/*
 * Copyright (C) 2016  Nexell Co., Ltd.
 * Author: DeokJin, Lee <truevirtue@nexell.co.kr>
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

        .align 5
//==================================================================
// Cache Invalidation code for Cortex-A9
//==================================================================

//==================================================================
// Invalidate entire branch predictor
//==================================================================
.global Invalidate_entire_branch_predictor
Invalidate_entire_branch_predictor:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c5, 0	//; invalidate all instruction caches
        mcr     p15, 0, r0, c7, c5, 6	//; BPIALL - Invalidate entire branch predictor array
        bx      lr

//==================================================================
// Cache control
//==================================================================
.global flushICache
flushICache:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c5, 0

        mov     pc, lr
        b       .

.global cache_delay_ms
cache_delay_ms:
	subs	r0, r0, #1
	bne	cache_delay_ms
	bx	lr

/* ------------------------------------------
 * Non-Secure Access Control Register
 * ------------------------------------------
 */

.global armv7_get_cpuid
armv7_get_cpuid:
        mrc     p15, 0, r0, c0, c0, 5		// Get our cpu id
        ands    r0, r0, #0xF			// Save CPU id
        bx	lr

.global arm9_get_mpidr
arm9_get_mpidr:
	mrc	p15, 0, r0, c0, c0, 5		// Get MPIDR
	bx	lr

.global armv7_set_fiq_cpsr
armv7_set_fiq_cpsr:
	msr	CPSR_c,  #(MODE_MON|I_Bit)
	bx	lr

.global set_svc_mode
set_svc_mode:
	msr	CPSR_c,  #(Mode_SVC|I_Bit)
	bx	lr
