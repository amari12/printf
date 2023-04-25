#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, i = 21, j = -21;
	unsigned int ui, uj;
	void *addr;
	unsigned long int num1 = 0x12345678UL;
	unsigned short int num2 = 0xABCD;

	ui = (unsigned int)INT_MAX + 1024;
	uj = 56;
	addr = (void *)0x7ffe637541f0;
	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	_printf("Binary of 125: %b\n", 125);
	_printf("Binary of 65: %b\n", 65);
	_printf("Binary of 99: %b\n", 99);
	_printf("Hex of *: %x\n", '*');
	_printf("HEX of *: %X\n", '*');
	_printf("Hex of 8: %x\n", '8');
	_printf("Hex of q: %x\n", 'q');
	_printf("HEX of Q: %X\n", 'Q');
	_printf("HEX of 8: %X\n", '8');
	_printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned octal of 56:[%o]\n", uj);
	_printf("Unsigned:[%u]\n", ui);
	_printf("Rev String:[%r]\n", "I am a string !");
	_printf("%R\n", "I am a string !");
	_printf("Length:[%+d, %+i]\n", i, j);
	_printf("Space flag: [% d, % i]\n", i, j);
	_printf("Hash flag: [%#d, %#i]\n", i, j);
	_printf("Multiple flags test: [%+#d, %+#d]\n", i, j);
	_printf("Address:[%p]\n", addr);
	_printf("%ld %hd\n", 1234567890L, (short)-12345);
	_printf("%lx %hx\n", num1, num2);
	return (0);
}
