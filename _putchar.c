#include <unistd.h>

/**
 * _putchar - writes c to stdout
 * @c: prints character
 *
 * Return:  1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
