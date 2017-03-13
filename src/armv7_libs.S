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
#include "nx_pyrope.h"

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
