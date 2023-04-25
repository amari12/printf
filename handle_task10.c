#include "main.h"
#include <stdarg.h>
#include <math.h>
#include <float.h>

/**
 * precision - Handle the precision for non-custom conversion specifiers
 * @inputs: args
 * Return: void
 */

void precision(va_list inputs)
{
	double fraction, number;
	int precision, integer, digit;

	number = va_arg(inputs, double);
	integer = (int) number;
	precision = va_arg(inputs, int);
	if (integer < 0)
	{
		_putchar('-');
		integer = -integer;
	}
	if (integer >= 10)
	{
		precision -= (int) (log10(integer) + 1);
		integer %= (int) pow(10, log10(integer));
	}
	while (precision-- > 0)
	{
		_putchar('0');
	}
	_putchar('.');/*print the fractional part*/
	fraction = number - (double) integer;
	while (precision-- > 0)
	{
		fraction *= 10;
		_putchar('0');
	}
	while (fraction > DBL_EPSILON)
	{
		digit = (int) floor(fraction);
		_putchar('0' + digit);
		fraction -= digit;
		fraction *= 10;
		if (--precision == 0)
		{
			break;
		}
	}
}

