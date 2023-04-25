#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _print_str - prints a string
 * @inputs: va_list of arguments
 * Return: int (nr of chars printed)
 */

int _print_str(va_list inputs)
{
	int counter = 0;
	int i;
	char *str = va_arg(inputs, char *); /*get string from va_list*/

	if (str == NULL)
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
	{ /*loop through str/inputs*/
		_putchar(str[i]); /*print value at address*/
		counter++; /*increase counter for each char printed*/
	} /*for*/
	return (counter);
} /*_print_str*/

