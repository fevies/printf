#include "main.h"
#include <stdarg.h>

/**
 * printf - custom printf function
 * @format: the format specifier
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
    int characters_printed = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                custom_putchar(c);
                characters_printed++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    characters_printed += custom_puts(str);
                }
                else
                {
                    characters_printed += custom_puts("(null)");
                }
            }
            else if (*format == '%')
            {
                custom_putchar('%');
                characters_printed++;
            }
            format++;
        }
        else
        {
            custom_putchar(*format);
            characters_printed++;
            format++;
        }
    }

    va_end(args);
    return characters_printed;
}
