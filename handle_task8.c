#include <stdarg.h>
#include "main.h"

/**
 * _print_long - prints long int as a str
 * @inputs: args
 * Return: int
 */

int _print_long(va_list inputs)
{
	long int num;
	char buffer[32];
	int i, index = 0;

	num = va_arg(inputs, long);
	if (num < 0) /*handling the negative*/
	{
		_putchar('-');
		num = -num;
	}
	do {
	       /* extracts the digits of num and stores them in buffer rev order */
		buffer[index++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	{ /* print in rev*/
		for (i = index - 1; i >= 0; i--)
		{
			_putchar(buffer[i]);
		}
	}
	return (index);
}  /*print long */


/**
 * _print_short - short ints
 * @inputs: args
 * Return: int
 */

int _print_short(va_list inputs)
{
	short int num;
	char buffer[16];
	int i,  index = 0;

	num = va_arg(inputs, int);
	if (num < 0)
	{/* negative numbers */
		_putchar('-');
		num = -num;
	}
	do {
		buffer[index++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return (index);
}

