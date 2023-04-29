#include <unistd.h>

/**
 * _putchar - print char with stdout
 * @ch: char to print
 * Return: Output.
 */
int _putchar(char c)
{
	static int cor;
	static char buffer[1024];

	if (c == -1)
	{
		cor = 0;
		return (0);
	}
	if (c == -2 || cor == 1024)
	{
		write(1, buffer, cor);
		cor = 0;
	}
	if (c != -1 && c != -2)
	{
		buffer[cor] = c;
		cor++;
		return (1);
	}
