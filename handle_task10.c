#include "main.h"
#include <ctype.h>

/**
 * precision - Calculates the precision for printing
 * @format: where we print the arguments
 * @i: List of args to be printed.
 * @inputs: args.
 * Return: Precision.
 */

int precision(const char *format, int *i, va_list inputs)
{
	int index = *i + 1;
	int precision = -1;

	if (format[index] == '.')
	{
		precision = 0;
		index++;
	}
	if (format[index] == '*')
	{
		index++;
		precision = va_arg(inputs, int);
	}
	else
	{
		while (isdigit(format[index]))
		{
			precision = precision * 10 + (format[index] - '0');
			index++;
		}
	}
	*i = index - 1;
	return (precision);
}
