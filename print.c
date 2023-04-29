#include "main.h"

/**
 * printc - prints a character.
 * @pa: 000 char.
 * @format: formatc
 * Return: 1
 */
int print(char *format, va_list pa)
{
	(void)format;
	_putchar(va_arg(pa, int));
	return (1);
}
