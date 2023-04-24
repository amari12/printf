#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list inputs;
	int printed_chars = 0; /*count and return*/
	int i; /*loop*/

	va_start(inputs, format); /*open va_list*/

	for (i = 0; format && format[i] != '\0'; i++)
	{ /*loop through format string if string and char exists*/
		if (format[i] == '%')
		{
			i++; /*move to char after % */
		/*handle conversion specifiers, format string, address i, inputs/args*/
			printed_chars += handle_conversion(format, &i, inputs);
		} /*if*/
		else /*not %*/
		{
			_putchar(format[i]); /*print normal char*/
			printed_chars++; /*increase count*/
		} /*else*/
	} /*for*/

	va_end(inputs); /*close list*/
	return (printed_chars);
} /*_printf*/

