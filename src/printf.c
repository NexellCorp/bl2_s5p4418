/*
 * Copyright (C) 2016  Nexell Co., Ltd. All Rights Reserved.
 * Nexell Co. Proprietary & Confidential
 *
 * Nexell informs that this code and information is provided "as is" base
 * and without warranty of any kind, either expressed or implied, including
 * but not limited to the implied warranties of merchantability and/or
 * fitness for a particular puporse.
 * 
 * Module	: print
 * File		: printf.c
 * Description	:
 * Author	: Hans
 * History	: 2017.02.28 new release
 */
#include <stdarg.h>
#include "nx_type.h"
#include "printf.h"


#define PAD_RIGHT	1
#define PAD_ZERO	2

static int printstring(const char *string, int width, int pad)
{
	register int cc = 0, padchar = ' ';
	register char ch;

	if (width > 0) {
		register int len = 0;
		register const char *ptr = string;
		if (pad & PAD_ZERO)
			padchar = '0';
		while (*ptr++)
			++len;
		if (len >= width)
			width = 0;
		else
			width -= len;
	}

	if (!(pad & PAD_RIGHT)) {
		while (width--) {
			putchar(padchar);
			++cc;
		}
	}

	do {
		ch = *string++;
		putchar(ch);
		++cc;
	} while (ch);

	for (; width > 0; --width) {
		putchar(padchar);
		++cc;
	}

	return cc;
}

/* the following should be enough for 32 bit int */
#define BUF_LEN 12
static int printnumber(int i, int b, int sg,
		int width, int pad, int letbase)
{
	char buf[BUF_LEN];
	register char *s;
	register int t, neg = 0, cc = 0;
	register unsigned int u = i;

	if (i == 0)
		return printstring("\0", width, pad);

	if (sg && b == 10 && i < 0) {
		neg = 1;
		u = -i;
	}

	s = buf + BUF_LEN - 1;
	*s = '\0';

	while (u) {
		t = u % b;
		if (t >= 10)
			t += letbase - '0' - 10;
		*--s = t + '0';
		u /= b;
	}

	if (neg) {
		if (width && (pad & PAD_ZERO)) {
			putchar('-');
			++cc;
			--width;
		} else
			*--s = '-';
	}

	return cc + printstring(s, width, pad);
}

int printf(const char *format, ...)
{
	va_list args;
	register int cc = 0;

	va_start(args, format);

	for (; *format != 0; ++format) {
		register int width, pad;
		char ch, chbase;

		ch = *format;
		if (ch != '%') {
			putchar(ch);
			++cc;
			continue;
		}
		ch = *++format;
		width = pad = 0;
		if (ch == '\0')
			break;
		if (ch == '%') {
			putchar(ch);
			++cc;
		}
		if (ch == '-') {
			ch = *++format;
			pad = PAD_RIGHT;
		}
		while (ch == '0') {
			ch = *++format;
			pad |= PAD_ZERO;
		}
		while (ch >= '0' && ch <= '9') {
			width *= 10;
			width += ch - '0';
			ch = *++format;
		}

		chbase = (ch & 0xE0) | 1;
		switch (ch) {
		case 'd':
			cc += printnumber(va_arg(args, int),
					10, 1, width, pad, chbase);
			continue;
		case 'u':
			cc += printnumber(va_arg(args, int),
					10, 0, width, pad, chbase);
			continue;
		case 'x':
		case 'X':
			cc += printnumber(va_arg(args, int),
					16, 0, width, pad, chbase);
			continue;
		case 'c': {
			char scr[2];
			scr[0] = (char)va_arg(args, int);
			scr[1] = '\0';
			cc += printstring(scr, width, pad);
			continue;
		}
		case 's': {
			register char *s = (char *)va_arg(args, int);
			cc += printstring(s ? s : "(null)", width, pad);
			continue;
		}
		default:
			continue;
		}
	}

	va_end(args);

	return cc;
}

