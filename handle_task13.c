#include "main.h"
#include <string.h>
#include <stdarg.h>

/**
 * _print_str_rev - prints string in reverse
 * @inputs: va_list inputs/arguments
 * Return: int (nr chars printed)
 */

int _print_str_rev(va_list inputs)
{
	char *str;
	int i = 0, len = 0;

	str = va_arg(inputs, char *); /*get string from arguments*/
	len = strlen(str);
	for (i = len - 1; i >= 0; i--)
	{ /*to print in rev*/
		_putchar(str[i]);
	} /*for*/
	return (len);
} /*_print_str_rev*/

