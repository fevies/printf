/**
 * _printf - Custom printf function
 * @format: the format specifier
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == '\0') // Check for trailing '%'
                break;

            if (*format == 'c') // Character
            {
                char c = va_arg(args, int);
                write(1, &c, 1); // Write the character to stdout
                printed_chars++;
            }
            else if (*format == 's') // String
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    while (*str)
                    {
                        write(1, str, 1); // Write each character to stdout
                        str++;
                        printed_chars++;
                    }
                }
                else
                {
                    write(1, "(null)", 6); // Write "(null)" for NULL string
                    printed_chars += 6;
                }
            }
            else if (*format == '%') // Percent sign
            {
                write(1, "%", 1); // Write '%' to stdout
                printed_chars++;
            }
            else
            {
                write(1, "%", 1); // Write '%' for unsupported specifier
                printed_chars++;
                write(1, format, 1); // Write the character immediately following '%'
                printed_chars++;
            }
        }
        else
        {
            write(1, format, 1); // Write non-format characters to stdout
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

