#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * print_0 - %0
 * @str: string
 * @width: width
 * Return: int
 */

int  print_0(const char *str, int width)
{
	int num_0, len, i;

	len = strlen(str);
	if (len < width)
	{
		num_0 = width - len;
		for (i = 0; i < num_0; i++)
		{
			_putchar('0');
		}
	}
	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_00 - %0
 * @str: string
 * @width: width
 * Return: int
 */

int print_00(const char *str, int width)
{
	int num_0, i, len = strlen(str);

	if (len < width)
	{
		num_0 = width - len;
		for (i = 0; i < num_0; i++)
		{
			_putchar('0');
		}
	}
	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
