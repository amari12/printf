#include "main.h"
#include <stdarg.h>
#include <ctype.h>

/**
 * handle_conversion - handles coversion specifiers and prints accordingly
 * @format: format string
 * @i: index
 * @inputs: va_list of inputs/arguments
 * Return: void for now
 */

int handle_conversion(const char *format, int *i, va_list inputs)
{
	int printed_chars = 0, width = 5, nr; /*nr for print int*/
	char *str = "hi", c;

	switch (format[*i])
	{
		case 'c':
			c = va_arg(inputs, int);
			_putchar(c);
			printed_chars++;
			break;
		case 's': /*ptr = va_arg(inputs, char);*/
			printed_chars += _print_str(inputs);
			break;
		case '%':
			_putchar('%');
			printed_chars++;
			break;
		case 'd':case 'i':
			nr = va_arg(inputs, int);
			printed_chars += _print_int(nr);
			break;
		case 'b':
			printed_chars += _print_bin(inputs);
			break;
		case '0':
			printed_chars += print_0(str, width) + print_00(str, width);
			break;
		default: /*not followed by any of the above*/
			/* check second batch of format specifiers*/
			printed_chars += handle_conversion2(format, i, inputs);
			if (printed_chars == 0)
			{ /*second batch also came back with nothing*/
				c = format[*i];
				_putchar('%');
				_putchar(c);
				printed_chars += 2;
			}
			break;
	} /*switch*/
	return (printed_chars);
} /*handle_conversion*/

/**
 * handle_conversion2 - second part of switch
 * @format: format string
 * @i: index
 * @inputs: va_list input arguments
 * Return: int (printed chars)
 */

int handle_conversion2(const char *format, int *i, va_list inputs)
{
	int printed_chars = 0;

	switch (format[*i])
	{
		case 'r':
			printed_chars += _print_str_rev(inputs);
			break;
		case 'R':
			printed_chars += _print_rot13(inputs);
			break;
		case '+':
			/*printed_chars += _check_next_flag(format, i ,inputs);*/
			printed_chars += _print_plus(format, i, inputs);
			break;
		case ' ':
			/*printed_chars += _check_next_flag(format, i ,inputs);*/
			printed_chars += _print_space(format, i, inputs);
			break;
		case '#':/*printed_chars += _check_next_flag(format, i ,inputs);*/
			printed_chars += _print_zeros(format, i, inputs);
			break;
		case 'o':
			printed_chars += _print_oct(inputs);
			break;
		case 'u':
			printed_chars += _print_ud(inputs);
			break;
		case 'x':
			printed_chars += _print_hex_small(inputs);
			break;
		case 'X':
			printed_chars += _print_hex(inputs);
			break;
		default: /*go back to handle_conversion() */
			printed_chars += handle_conversion3(format, i, inputs);
			if (printed_chars == 0)
				return (0); /*no match*/
			break;
	} /*switch*/
	return (printed_chars); /*if there was a match*/
} /*handle conversion2 */

/**
 * handle_conversion3 - handles coversion specifiers and prints accordingly
 * @format: format string
 * @i: index
 * @inputs: va_list of inputs/arguments
 * Return: void for now
 */

int handle_conversion3(const char *format, int *i, va_list inputs)
{
	int printed_chars = 0, nr, width;

	switch (format[*i])
	{
		case 'S':/* print non printable chars*/
			printed_chars += _print_npc(inputs);
			break;
		case 'p':
			printed_chars += _print_ptr(inputs);
			break;
		default: /*not followed by any of the above*/
			printed_chars += handle_conversion_l_h(format, i, inputs);
			if (isdigit(format[*i]))
			{
				width = format[*i] - '0';
				nr = va_arg(inputs, int);
				printed_chars += _print_int_width(nr, width);
				*i = *i + 1;
			}
			if (printed_chars == 0)
				return (0);
			break;
	}
	return (printed_chars);
}

/**
 * handle_conversion_l_h - handles the long and short formats
 * @format: either long l or short h
 * @i: index
 * @inputs: input arguments
 * Return: printed_chars
 */

int handle_conversion_l_h(const char *format, int *i, va_list inputs)
{
	int printed_chars = 0/*, nr*/;
	/*char c;*/
	int *j = i;

	switch (format[*i])
	{
		case 'l':
			(*j)++;
			switch (format[*j])
			{
				case 'i':case 'd':case 'u':case 'o':case 'x':case 'X':
					printed_chars += handle_conversion(format, j, inputs);
					break;
				default:
					break;
			}
			printed_chars += _print_long(inputs);
			break;
		case 'h':
			(*j)++;
			switch (format[*j])
			{
				case 'i':case 'd':case 'u':case 'o':case 'x':case 'X':
					printed_chars += handle_conversion(format, j, inputs);
					break;
				default:
					break;
			}
			printed_chars += _print_short(inputs);
			break;
		default:
			printed_chars = 0; /*no match*/
			break;
	}
	return (printed_chars);
}
