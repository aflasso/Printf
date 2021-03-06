#include "holberton.h"

/**
 * _printf - Produces output according to format.
 * @format: conversion specifires.
 * Return: The number of characters to print.
 */
int _printf(const char *format, ...)
{
	char in[11];
	int x;
	int i;
	int c;
	int p = 0;
	char *s;
	va_list arguments;

	va_start(arguments, format);

	while (format[p] != '\0')
	{
		if (format[p] != '%')
		{
			write(1, &format[p], 1);
			p++;

		}
		if (format[p] == '%')
		{
			if (format[p + 1] == 's')
			{
				s = va_arg(arguments, char *);
				write(1, s, strlen(s));
				p++;
			}
			if (format[p + 1] == 'c')
			{
				c = va_arg(arguments, int);
				write(1, &c, 1);
				p++;
			}
			if (format[p + 1] == 'd')
			{
				i = va_arg(arguments, int);
				x = conv(i, in);
				write(1, in, x);
				p++;
			}
			if (format[p + 1] == 'i')
			{
				i = (int) va_arg(arguments, int);
				x = conv(i, in);
				write(1, in, x);
				p++;
			}
			if (format[p + 1] == '%')
			{
				case_porc('%');
				p++;

			}
			if (format[p + 1] == 'u')
			{
				p++;
			}
			else
			{
				p++;

			}

		}


	}
	va_end(arguments);
	return (p);
}

/**
 * conv - converts an int to a string.
 * @n: the int to be changed.
 * @str: the new string
 * Return: the number of character.
 */
int conv(int n, char str[])
{
	int p = 0;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}

	if (n < 0)
	{
		while (n)
		{
			str[p] = ((n % 10) * -1 + '0');
			n = n / 10;
			p++;
		}
		str[p] = '-';
		p++;
	}

	if (n > 0)
	{
		while (n)
		{

			str[p] = (n % 10) + '0';
			n = n / 10;
			p++;
		}
	}


	reverse(str, p);

	str[p] = '\0';
	return (p);
}

/**
 * reverse - reverse a string.
 * @str: the string to be changed
 * @len: the lenght of the string.
 */
void reverse(char *str, int len)
{
	int p = 0;
	int temp;
	int til = len / 2;
	int final = len - 1;

	while (p < til)
	{
		temp = str[p];
		str[p] = str[final];
		str[final] = temp;
		p++;
		final--;
	}
}

/**
 * case_porc - print with format %%.
 * @porcnt: the porcent character
 */
void case_porc(char porcnt)
{
	write(1, &porcnt, 1);
}