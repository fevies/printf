#include "main.h"

/**
 * get_function - function specifiers.
 *
 * @con_spec: Conversion specifiers.
 * @args: arguments.
 *
 * Return: char count.
 */

int get_function(char con_spec, va_list args)
{
	int a = 0;
	int count_fun = 0;

	specifiers_t spec[] = {
		{'c', print_char},
		{'s', string},
		{'%', mod},
		{'d', dgt},
		{'i', dgt},
		{'r', rev_string},
		{0, NULL}
	};

	while (spec[a].specifiers)
	{
		if (const_sec == sec[a].specifiers)
			c_fun += sec[a].f(args);
		a++;
	}

	if (c_fun == 0)
	{
		c_fun += _putchar('%');
		c_fun += _putchar(con_spec);
	}

	return (c_fun);
}
