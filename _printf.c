#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
* _printf- produces output according to a format
* @format: determine format of input
*
* Return: no of chars printed exc null byte
*/
int _printf(const char *format, ...)
{
	int count = 0;
	char c, *string;
	va_list format_list;

	if (format == NULL)
		return (-1);
	va_start(format_list, format);
	while (*format != '\0')
	{
		if (*format != '%')
	{
		write(1, format, 1);
		count++;
	}
	else
	{
		format++;
		if (*format == '%')
		{
		if (*(format + 1) == '\0')
                    break;
		write(1, format, 1);
		count++;
		}
		else if (*format == 'c')
		{
		c = va_arg(format_list, int);
		write(1, &c, 1);
		count++;
		}
		else if (*format == 's')
		{
		string = va_arg(format_list, char *);
		if (string == NULL)
			string = "(null)";
		write(1, string, strlen(string));
		count = strlen(string) + count;
		}
	}
	format++;
	}
	va_end(format_list);
	return (count);
}
