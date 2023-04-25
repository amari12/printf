#include "main.h"
#include <stddef.h>

/**
 * _print_npc - print string and the non printable chars
 * @inputs: args
 * Return: int
 */

int _print_npc(va_list inputs)
{
	char *str;
	int i, counter = 0;

	str = va_arg(inputs, char*);
	if (str == NULL)
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar((str[i] / 16) + '0');
			_putchar((str[i] % 16) + ((str[i] % 16 < 10) ? '0' : 'A' - 10));
			counter += 4;
		}
		else
		{
			_putchar(str[i]);
			counter++;
		}
	}
	return (counter);
}
