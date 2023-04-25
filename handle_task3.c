#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * _print_hex - prints number in hexadecimal format
 * @inputs: va_list inputs
 * Return: int (nr of chars printed)
 */

int _print_hex(va_list inputs)
{
	int number;
	int length = 0, j = 0, i, temp, counter = 0;
	char hex[100];

	number = va_arg(inputs, int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	while (number)
	{
		temp = number % 16;

		/* conversion*/
		if (temp < 10)
			temp += 48;
		else
			temp += 55;

		length += 1;
		hex[j++] = temp;
		/*next digit*/
		number = number / 16;
	} /*while*/

	/*printing*/
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
		counter++;
	}
	return (counter);

} /*_print_hex*/

/**
 * _print_hex_small - prints hexadecimal in small letters
 * @inputs: input arguments
 * Return: int (printed chars)
 */

int _print_hex_small(va_list inputs)
{
	int number;
	int length = 0, j = 0, i, temp, counter = 0;
	char hex[100];

	number = va_arg(inputs, int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	while (number)
	{
		temp = number % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 55;
		if (temp >= 65 && temp <= 70)
			temp += 32;
		length += 1;
		hex[j++] = temp;
		number = number / 16;
	} /*while*/
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
		counter++;
	} /*for print*/
	return (counter);
} /*print hex small*/

/**
 * _print_oct - prints octal representation of input
 * @inputs: va_list inputs
 * Return: int (nr of chars printed)
 */

int _print_oct(va_list inputs)
{
	int i = 0, counter = 0;
	unsigned int value;
	char oct[100];

	value = va_arg(inputs, unsigned int); /*initialise*/

	while (value != 0)
	{ /*do conversion one digit at a time*/
		oct[i] = (value % 8) + '0';
		value = value / 8;
		i++;
		counter++;
	} /*while*/
	oct[i] = '\0'; /*string terminator*/
	/*for loop to putchar string*/
	for (i = counter; i >= 0; i--)
	{
		_putchar(oct[i]);
	} /*for*/
	return (counter);
} /*_print_oct*/

/**
 * _print_ud - prints an insigned int
 * @inputs: variadic list of inputs
 * Return: the number of printed digits
 */

int _print_ud(va_list inputs)
{
	unsigned int num, cp, p = 1;
	int counter = 1, digit, i;

	/*arg to uns int*/
	num = va_arg(inputs, unsigned int);
	/*count the number of digits */
	cp = num;
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (cp >= 10)
	{
		cp /= 10;
		counter++;
	}
	/*calculate the power of 10 needed for the leftmost digit*/
	for (i = 1; i < counter; i++)
	{
		p *= 10;
	}
	/* print the digits in rev order*/
	while (counter > 0)
	{
		digit = (num / p) % 10;
		_putchar('0' + digit);
		p /= 10;
		counter--;
	}
	return (counter + 1);
}

