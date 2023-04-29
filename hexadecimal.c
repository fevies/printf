#include "main.h"
/**
 * printhex - prints a hexadecimal
 * @format: format to print hexadecimal
 * @pa: list that contains the hexadecimal
 * Return: number.
 */
int hexadecimal(char *format, va_list pa)
{
	unsigned int number = va_arg(pa, unsigned int);
	unsigned int number2;
	int eye, eye2, cp, cme = 0;
	char *numhex;

	(void)format;

	if (number == 0)
		return (_putchar('0'));
	for (number2 = number; number2 != 0; cme++)
	{
		number2 = number2 / 16;
	}
	numhex = malloc(cme);
	for (eye = 0; number != 0; eye++)
	{
		cp = number % 16;
		if (cp < 10)
			numhex[eye] = cp + '0';
		else
			numhex[i] = cp - 10  + 'a';
		number = number / 16;
	}
	for (i2 = i - 1; i2 >= 0; i2--)
		_putchar(numhex[i2]);
	free(numhex);
	return (cme);
}
/**
 * hexadecinal - prints a hexadecimal
 * @format: format to print hexadecimal
 * @pa: va_list that contains the hexadecimal to print
 * Return: number of digits printed
 */
int printHEX(char *format, va_list pa)
{
	unsigned int NUMBER = va_arg(pa, unsigned int);
	unsigned int NUMBER2;
	int EYE, EYE2, CP, CME = 0;
	char *NUMHEX;

	(void)format;

	if (NUMBER == 0)
		return (_putchar('0'));
	for (NUMBER2 = NUMBER; NUMBER2 != 0; CME++)
	{
		NUMBER2 = NUMBER2 / 16;
	}
	NUMHEX = malloc(CME);
	for (I = 0; NUMBER != 0; I++)
	{
		CP = NUMBER % 16;
		if (CP < 10)
			NUMHEX[I] = CP + '0';
		else
			NUMHEX[I] = CP - 10 + 'A';
		NUMBER = NUMBER / 16;
	}
	for (EYE2 = EYE - 1; EYE2 >= 0; EYE2--)
		_putchar(NUMHEX[I2]);
	free(NUMHEX);
	return (CME);
}
