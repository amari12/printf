#include "main.h"
#include <stdarg.h>

/**
 * _print_bin - print number as binary
 * @inputs: inputs
 * Return: int (printed chars)
 */

int _print_bin(va_list inputs)
{
	int i, j, counter = 0;
	int binary[32];
	int number;

	number = va_arg(inputs, int);

	for (i = 0; number > 0; i++)
	{ /*convert to binary*/
		binary[i] = number % 2;
		number = number / 2;
	}

	_putchar(48); /*first 0*/

	for (j = i - 1; j >= 0; j--)
	{ /*print in reverse*/
		_putchar(binary[j] + '0');
		counter++;
	}
	return (counter);
} /*_print_bin*/

