#include "holberton.h"

/**
 * _printf - Produces output according to format.
 * @format: conversion specifires.
 * Return: The number of characters to print.
 */
int _printf(const char *format, ...)
{
	int p = 0;

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
			

		}
	}
	va_end(arguments);
	return (p);
}

int (*get_format_func(char *s))(va_list)
{
	
}

void case_s(va_list a)
{
	char *s;

	s = va_arg(a, char *);
	write(1, s, strlen(s));
}

void case_c(va_list a)
{
	int c;

	c = va_arg(a, int);
	write(1, &c, 1);
}

void case_d(va_list a)
{
	int d;
	int x;
	char in[11];

	d = va_arg(a, int);
	x = conv(d, in);
	write(1, in, x);
}

void case_i(va_list a)
{
	int d;
	int x;
	int in[11];

	d = va_arg(a, int);
	x = conv(d,in);
	write(1, in, x);
}

/**
 * case_porc - print with format %%.
 * @porcnt: the porcent character
 */
void case_porc(char porcnt)
{
	write(1, &porcnt, 1);
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
