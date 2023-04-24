#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

/**
 * _print_ptr - prints the value of a ptr
 * @inputs: args
 * Return: int
 */

int _print_ptr(va_list inputs)
{
	void *ptr;
	char hex[] = "0123456789abcdef";
	char buffer[32];
	char *p;
	uintptr_t num;
	int len = 0;

	ptr = va_arg(inputs, void*);
	p = buffer + sizeof(buffer - 1);
	*--p = '\0';
	num = (uintptr_t)ptr;
	do {
		*--p = hex[num % 16];
		num /= 16;
	} while (num != 0);
	*--p = 'x';
	*--p = '0';
	while (*p)
	{
		_putchar(*p++);
		len++;
	}
	return (len);
}

