#include "main.h"

/**
 * _puts - prints a string
 * new line, to stdout.
 * @string: input string
 * Return: count of string.
 */
int _puts(char *string)
{
	int cor = 0;

	while (*string)
	{
		_putchar(*string);
		string++;
		cor++;
	}
	return (cor);
}
