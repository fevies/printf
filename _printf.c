#include <stdarg.h>  // for variable arguments
#include <unistd.h>  // for write function

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;  // To keep track of the number of characters printed

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            // If not a '%', simply write the character to stdout
            write(1, format, 1);
            count++;
        }
        else
        {
            format++;  // Move past the '%'

            if (*format == '\0')
                break;  // Exit if '%' is the last character in the format string

            switch (*format)
            {
                case 'c':
                {
                    // Handle character specifier
                    char c = va_arg(args, int);  // char is promoted to int
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's':
                {
                    // Handle string specifier
                    const char *str = va_arg(args, const char *);
                    int len = 0;
                    while (str[len])
                        len++;
                    write(1, str, len);
                    count += len;
                    break;
                }
                case '%':
                {
                    // Handle the '%' specifier
                    write(1, "%", 1);
                    count++;
                    break;
                }
                default:
                    // Handle unsupported format specifiers
                    write(1, "%", 1);  // Print the '%' character
                    write(1, format, 1);  // Print the unknown character
                    count += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}
