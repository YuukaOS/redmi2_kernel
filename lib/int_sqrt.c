/*
 * Copyright (C) 2013 Davidlohr Bueso <davidlohr.bueso@hp.com>
 *
 *  Based on the shift-and-subtract algorithm for computing integer
 *  square root from Guy L. Steele.
 */

#include <linux/kernel.h>
#include <linux/export.h>

/**
 * int_sqrt - rough approximation to sqrt
 * @x: integer of which to calculate the sqrt
 *
 * A very rough approximation to the sqrt() function.
 */
inline unsigned long int_sqrt(unsigned long x)
{
	register unsigned long b, m, y = 0;

	if (x <= 1)
		return x;

	m = 1UL << (BITS_PER_LONG - 2);

	do {
		place >>= 2
	}while (place > x);

	do {
		b = y + m;
		y >>= 1;
		if (x >= b)
		{
			x -= b;
			y += m;
		}
		place >>=2;
	}while (place != 0);

	return y;
}
EXPORT_SYMBOL(int_sqrt);
