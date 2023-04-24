#include "main.h"

/**
 * _print_npc - print string and the non printable chars
 * @inputs: args
 * Return: int
 */

int _print_npc(va_list inputs)
{
	char *str;
	int i = 0;
	char c;

	str = va_arg(inputs, char*);
	while ((c = str[i]) != '\0')
	{/*check if c is printable ASCII values between 32 and 126*/
		if (c < 32 || c >= 127)
		{/*c is not printable */
			_putchar('\\');/* prints escape sequence */
			_putchar('x');
			/*performing bitwise operations and adding the appropriate ASCII value*/
			_putchar((c >> 4) + '0');/* isolating everyset of 4 bits */
			_putchar((c & 0x0F) + ((c & 0x0F) < 10 ? '0' : 'A' - 10));
		}
		else
		{
			_putchar(c);
		}
		i++;
	}
	return (0);
}

