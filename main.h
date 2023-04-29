#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct specifiers
{
	char specifiers;
	int (*f)(va_list);
} specifiers_t;

int get_function(char s, va_list args);
int _putchar(char c);
int _printf(const char *format, ...);


int print_digit(va_list args);
int print_mod(va_list args);
int print_rev_string(va_list args);
int print_char(va_list args);
int print_string(va_list args);


#endif
