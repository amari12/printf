#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <math.h>

/**
 * _print_int_width - prints numbers
 * @nr: nr to print
 * @width: width of print
 * Return: int (nr of chars printed)
 */

int _print_int_width(int nr, int width)
{
	int counter = 0, count = 0, i;
	int int_char; /*single digit to print using putchar*/
	int number = nr; /*going to change*/
	int power_of_10 = 1;

	if (nr == 0) /*check if exists*/
	{
		_putchar('0');
		return (1);
	}
	if (number < 0)
	{ /*if negative, change to positive and write -*/
		number = -number;
		_putchar('-');
		counter++;
	}
	while (number / power_of_10 > 0)
	{ /*get length and add to nr of chars printed*/
		power_of_10 *= 10;
		count++;
	}
	power_of_10 /= 10;
	counter += count;
	for (i = 0; i < (width - counter); i++)
	{
		_putchar(' ');
	}
	/*print digit when end of recursion is reached & traverse back*/
	while (count > 0)
	{
		int_char = nr / power_of_10;
		_putchar(int_char + '0');
		nr = nr % power_of_10;
		count--;
		power_of_10 /= 10;
	}
	return (counter);
} /*_print_int_width*/
