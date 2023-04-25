#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _print_int - prints numbers
 * @nr: nr to print
 * Return: int (nr of chars printed)
 */

int _print_int(int nr)
{
	int counter = 0, count = 0;
	int int_char; /*single digit to print using putchar*/
	int number = nr; /*going to change*/
	int *ptr;

	ptr = &nr;
	if (ptr == NULL)
		return (0);

	if (number < 0)
	{ /*if negative, change to positive and write -*/
		number = -number;
		_putchar('-');
		counter++;
	}

	if (number / 10 != 0)
	{ /*go through number until end using recursion*/
		_print_int(number / 10);
	}
	/*print digit when end of recursion is reached & traverse back*/
	int_char = number % 10;
	_putchar(int_char + '0');

	/*get length = nr of chars printed*/
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	counter += count;
	return (counter);
} /*_print_int*/

