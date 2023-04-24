#include "main.h"
#include <stdarg.h>
#include <ctype.h>

/**
 * _print_rot13 - print rot13 string
 * @inputs: input arguments
 * Return: int (char printed)
 */

int _print_rot13(va_list inputs)
{
	int i = 0, len = 0;
	char *str;
	char c;

	str = va_arg(inputs, char *);

	while (str[i])
	{
		c = str[i];
		if (isalpha(str[i])) /*if it's a valid char*/
		{
			if (c >= 'a' && c <= 'm')
				c += 13;
			else if (c >= 'A' && c <= 'M')
				c += 13;
			else if (c >= 'n' && c <= 'z')
				c -= 13;
			else if (c >= 'N' && c <= 'Z')
				c -= 13;
			_putchar(c);
		} /*if*/
		else
		{
			_putchar(c);
		} /*else*/
		i++; /*next char*/
		len++; /*increase count*/
	} /*while*/
	return (len);
} /*_print_rot13*/

