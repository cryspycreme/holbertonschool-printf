#include "main.h"
#include <stdio.h>
#include <stdarg.h> /*va_list*/
#include <string.h> /*strlen*/
#include <unistd.h> /*write*/

/**
* _printf1- produces output according to a format
* @format: determine format of input
*
* Return: no of ints printed exc null byte
*/
int _printf1(const char *format, ...)
{
	va_list args;
	int length = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}
			switch (*format) /*format specifier after % is evaluated*/
			{
				case 'd':
					length = length + print_dec(va_arg(args, int));
					break;
				case 'i':
					length = length + print_int(va_arg(args, int));
					break;
				default: /*if no cases match, run the default block*/
					length = length + write(1, "%", 1);
					length = length + write(1, format, 1);
					break;
			}
		}
		else
		{
			length = length + print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (length);
}
