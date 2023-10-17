#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

int my_printf(const char *format, ...) {
    int i, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list args;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return -1;

    va_start(args, format);

    for (i = 0; format && format[i] != '\0'; i++) {
        if (format[i] != '%') {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        } else {
            print_buffer(buffer, &buff_ind);
            flags = extract_flags(format, &i);
            width = obtain_width(format, &i, args);
            precision = fetch_precision(format, &i, args);
            size = acquire_size(format, &i);
            ++i;
            printed_chars += handle_output(format, &i, args, buffer, flags, width, precision, size);
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(args);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind) {
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}
