#include <unistd.h>
#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
int conv(unsigned int n, char str[]);
void reverse(char *, int len);

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
		else
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
				i = (int) va_arg(arguments, int);
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
	return (0);
}

int conv(unsigned int n, char str[])
{
	int p = 0;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}

	while (n)
	{
		str[p] = (n % 10) + '0';
		n = n / 10;
		p++;
	}
	reverse(str, p);
	str[p] = '\0';
	return (p);
}


void reverse(char *str, int len)
{
	int p = 0;
	int temp;
	int til = len / 2;

	while (p < til)
	{
		temp = str[p];
		str[p] = str[len];
		str[len] = temp;
		p++;
		len--;
	}
}

























