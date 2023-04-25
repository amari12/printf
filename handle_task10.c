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

	if (format[index] != '.')
		return (precision);

	precision = 0;

	for (index += 1; format[index] != '\0'; index++)
	{
		if (isdigit(format[index]))
		{
			precision *= 10;
			precision += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			precision = va_arg(inputs, int);
			break;
		}
		else
			break;
	}

	*i = index - 1;

	return (precision);
}
