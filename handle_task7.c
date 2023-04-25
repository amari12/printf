#include "main.h"
#include <stdarg.h>

/**
 * _print_plus - printes the sign of the number
 * @format: format string
 * @i: index
 * @inputs: input arguments
 * Return: int (printed chars nr)
 */

int _print_plus(const char *format, int *i, va_list inputs)
{
	int nr, counter = 0;
	/*check if format[i+1] is d/i here and call _print_int*/
	if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
	{
		nr = va_arg(inputs, int); /*get the number*/
		if (nr >= 0)
		{ /*positive or zero*/
			_putchar('+');
			counter += 1;
		}
		else if (nr < 0)
		{
			_putchar('-');
			nr = nr * -1; /*make positive*/;
			counter++;
		}
		counter += _print_int(nr); /*print the nr*/
		*i = *i + 1; /*skip next char (d/i)*/
	} /*if*/
	else /*not for a number*/
	{
		_putchar('%');
		_putchar(format[*i]);
		counter += 2;
	} /*else*/
	return (counter);
} /*_print_plus*/

/**
 * _print_space - prints a preceding space instead of +
 * @format: format string
 * @i: index
 * @inputs: input arguments
 * Return: int (printed chars)
 */

int _print_space(const char *format, int *i, va_list inputs)
{
	int nr, counter = 0;
	/*check if format[i+1] is d/i here and call _print_int*/
	if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
	{
		nr = va_arg(inputs, int); /*get the number*/
		if (nr >= 0)
		{ /*positive or zero*/
			_putchar(' ');
			counter += 1;
		}
		else if (nr < 0)
		{ /*negative is handled in _print_int()*/
			_putchar('-');
			nr = nr * -1; /*make positive*/
			counter++;
		}
		counter += _print_int(nr);
		*i = *i + 1; /*skip next char (d/i)*/
	} /*if*/
	else /*not for a number*/
	{
		_putchar('%');
		_putchar(format[*i]);
		counter += 2;
	} /*else*/
	return (counter);
} /*_print_space*/

/**
 * _print_zeros - prints zeros in front
 * @format: format string
 * @i: index
 * @inputs: input arguments
 * Return: int (printed chars)
 */

int _print_zeros(const char *format, int *i, va_list inputs)
{ /* %# */
	int nr, counter = 0;
	/*check if format[i+1] is d/i here and call _print_int*/
	if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
	{
		nr = va_arg(inputs, int); /*get the number*/
		if (nr >= 0 && format[*i - 1] == '+')
		{ /*if there's a %+ before*/
			_putchar('+');
			counter++;
		}
		else if (nr < 0)
		{
			_putchar('-');
			counter++;
			nr = nr * -1;
		}
		_putchar(0 + '0');
		counter += 1;
		counter += _print_int(nr);
		*i = *i + 1; /*skip next char (d/i)*/
	} /*if*/
	else /*not for a number*/
	{
		_putchar('%');
		_putchar(format[*i]);
		counter += 2;
	} /*else*/
	return (counter);
} /*_print_zeros*/

