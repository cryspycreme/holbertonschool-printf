#include "main.h"
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
			switch (*format)
			{
				case 'c':
					length = length + print_char(va_arg(args, int));
					break;
				case 's':
					length = length + print_string(va_arg(args, const char *));
					break;
				case '%':
					length = length + print_char('%');
					break;
				case 'd':
					length = length + print_d(va_arg(args, int));
					break;
				case 'i':
					length = length + print_i(va_arg(args, int));
					break;
				default:
					length = length + write(1, "%", 1) + write(1, format, 1);
			}
		}
		else
			length = length + print_char(*format);
		format++;
	}
	va_end(args);
	return (length);
}
