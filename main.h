#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct sps
{
	char sps;
	int (*f)(va_list);
} specifiers_t;

int firstfunc(char s, va_list args);
int _putchar(char c);
int _printf(const char *format, ...);


int dgt(va_list args);
int mod(va_list args);
int rev_string(va_list args);
int print_char(va_list args);
int string(va_list args);


#endif
