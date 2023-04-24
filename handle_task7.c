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

/**
 * _check_next_flag - handles multiple flags when printing numbers
 * @format: format string
 * @i: index
 * @inputs: input arguments
 * Return: int (chars printed)
 */

int _check_next_flag(const char *format, int *i, va_list inputs)
{
	int has_plus = 0, has_space = 0,
	    has_hash = 0, has_minus = 0, has_zero = 0;
	int reached_i_or_d = 0; /*to stop loop*/
	int *j; /*can change j while i stays constant*/
	int counter = 0, length = -1, c;

	j = i;
	while (reached_i_or_d == 0)
	{
		switch (format[*j])
		{
			case '+':
				has_plus = 1; /*flag*/
				j++; /*check next char for flag*/
				break; /*exit*/
			case ' ':
				has_space = 1;
				j++;
				break;
			case '#':
				has_hash = 1;
				j++;
				break;
			case '-':
				has_minus = 1;
				j++;
				break;
			case '0':
				has_zero = 1;
				j++;
				break;
			case 'i':
			case 'd':
				counter += _print_int_with_flags(inputs, has_plus,
					       	has_space, has_hash, has_minus, has_zero, length);
				reached_i_or_d = 1; /*end while loop*/
				break; 
			default:
				/*check if it's a number*/
				if ((int)format[*j] < 10 && (int)format[*i] > 0)
				{
					length = (int)format[*j];
					j++;
					break;
				}
				else /*did not end with i / d*/
				{
					_putchar('%');
					counter++;
					for (c = *i; c <= *j; c++)
					{ /*loop through flags to print*/
						_putchar(format[c]);
						counter++;
					} /*for*/
					reached_i_or_d = -1;
				} /*else*/
				break;
		} /*switch*/
	} /*while*/
	return (counter);
} /*check next flag*/

/**
 * _print_int_with_flags - handles multiple flags
 * @inputs:  i
 * @has_plus: i
 * @ has_space: i
 * @has_hash: i
 * @has_minus: i
 * @has_zero: i
 * @length: i
 * Return: int
 */

int _print_int_with_flags(__attribute__((unused)) va_list inputs, __attribute__((unused)) int  has_plus, __attribute__((unused)) int has_space, __attribute__((unused)) int has_hash, __attribute__((unused)) int has_minus, __attribute__((unused)) int has_zero, __attribute__((unused)) int length)
{
	return (0);
}
