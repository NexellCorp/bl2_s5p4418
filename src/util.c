/*
 * Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
 * Nexell Co. Proprietary & Confidential
 *
 * Nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular puporse.
 * This code is not allowed to redistribute without permission or
 * open to the public.
 * 
 * Module	:
 * File		:
 * Description	:
 * Author	: Hans
 * History	: 2017.02.28 new release
 */
#include "nx_chip.h"
#include "nx_type.h"
#include "nx_clkpwr.h"
#include "printf.h"

static volatile struct NX_CLKPWR_RegisterSet *const pReg_ClkPwr =
	(struct NX_CLKPWR_RegisterSet *const)PHY_BASEADDR_CLKPWR_MODULE;

u32 NX_CLKPWR_GetPLLFrequency(u32 PllNumber)
{
	u32 regvalue, regvalue1, nP, nM, nS, nK;
	u32 temp = 0;

	regvalue = pReg_ClkPwr->PLLSETREG[PllNumber];
	regvalue1 = pReg_ClkPwr->PLLSETREG_SSCG[PllNumber];
	nP = (regvalue >> PLL_P) & 0x3F;
	nM = (regvalue >> PLL_M) & 0x3FF;
	nS = (regvalue >> PLL_S) & 0xFF;
	nK = (regvalue1 >> PLL_K) & 0xFFFF;

	if ((PllNumber >= 2) && nK)
		temp = (((((nK * 1000) / 65536) * 24000) / nP) >> nS);

	temp = ((((nM * 24000) / nP) >> nS) * 1000) + temp;
	return temp;
}

void *memcpy(void *dest, const void *src, size_t n)
{
	const char *s = src;
	char *d = dest;

	while (n--)
		*d++ = *s++;

	return dest;
}

void *memset(void *str, int c, size_t n)
{
	char *pdata = str;
	while (n--)
		*pdata++ = c;
	return str;
}

int memcmp(const void* s1, const void* s2, size_t n)
{
	const char *src1 = s1, *src2 = s2;

	while (n--) {
		char res = *src1++ - *src2++;
		if (res)
			return (res);
	}
	return 0;
}

unsigned int getquotient(unsigned int dividend, unsigned int divisor)
{
	unsigned int quotient, remainder;
	unsigned int t, num_bits;
	unsigned int q, bit, d = 0;
	unsigned int i;

	remainder = 0;
	quotient = 0;

	if (divisor == 0)
		return -1;

	if (divisor > dividend) {
		return 0;
	}

	if (divisor == dividend) {
		return 1;
	}

	num_bits = 32;

	while (remainder < divisor) {
		bit = (dividend & 0x80000000) >> 31;
		remainder = (remainder << 1) | bit;
		d = dividend;
		dividend = dividend << 1;
		num_bits--;
	}

	dividend = d;
	remainder = remainder >> 1;
	num_bits++;

	for (i = 0; i < num_bits; i++) {
		bit = (dividend & 0x80000000) >> 31;
		remainder = (remainder << 1) | bit;
		t = remainder - divisor;
		q = !((t & 0x80000000) >> 31);
		dividend = dividend << 1;
		quotient = (quotient << 1) | q;
		if (q) {
			remainder = t;
		}
	}
	return quotient;
}

unsigned int getremainder(unsigned int dividend, unsigned int divisor)
{
	unsigned int quotient, remainder;
	unsigned int t, num_bits;
	unsigned int q, bit, d = 0;
	unsigned int i;

	remainder = 0;
	quotient = 0;

	if (divisor == 0)
		return -1;

	if (divisor > dividend) {
		return dividend;
	}

	if (divisor == dividend) {
		return 0;
	}

	num_bits = 32;

	while (remainder < divisor) {
		bit = (dividend & 0x80000000) >> 31;
		remainder = (remainder << 1) | bit;
		d = dividend;
		dividend = dividend << 1;
		num_bits--;
	}

	dividend = d;
	remainder = remainder >> 1;
	num_bits++;

	for (i = 0; i < num_bits; i++) {
		bit = (dividend & 0x80000000) >> 31;
		remainder = (remainder << 1) | bit;
		t = remainder - divisor;
		q = !((t & 0x80000000) >> 31);
		dividend = dividend << 1;
		quotient = (quotient << 1) | q;
		if (q) {
			remainder = t;
		}
	}
	return remainder;
}

void __div0(void)
{
	printf("divide by zero, halt!\r\n");
	while (1);
}

uint32_t __udivmodsi4(uint32_t num, uint32_t den)
{
	uint32_t quot = 0, qbit = 1;

	if (den == 0) {
		__div0();
		return -1;
	}

	/* Left-justify denominator and count shift */
	while ((int32_t) den >= 0) {
		den <<= 1;
		qbit <<= 1;
	}

	while (qbit) {
		if (den <= num) {
			num -= den;
			quot += qbit;
		}
		den >>= 1;
		qbit >>= 1;
	}

	return quot;
}

uint32_t __aeabi_uidiv(uint32_t num, uint32_t den)
{
	return __udivmodsi4(num, den);
}

