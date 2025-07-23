#include "main.h"
#include <string.h> /*strlen*/
#include <unistd.h> /*write*/
#include <limits.h> /*handles lower limit of int type*/
/**
 * print_char - prints a character
 *
 * @character: character to be printed
 * Return: no. bytes written.
 */

int print_char(char character)
{
	int c;

	c = write(1, &character, 1);
	return (c); /*as write prints but also returns the no. of bytes*/
}

/**
 * print_string - prints a string
 *
 * @string: string to be printed
 * Return: no. bytes written.
 */

int print_string(const char *string)
{
	int s;

	if (string == NULL)
		string = "(null)";
	s = write(1, string, strlen(string));
	return (s);
}

/**
 * print_d - prints a signed decimal integer.
 *
 * @number: number to be printed
 * Return: no. bytes written.
 */

int print_d(int number)
{
	int len = 0;

	if (number == INT_MIN)
	{
		return print_string("-2147483648");
	if (number < 0)
	{
		len = len + print_char('-');
		number = -number;
	}
	if (number >= 10)
	{
		len = len + print_d(number / 10);
	}

	len  = len + print_char(number % 10 + '0');

	return (len);
}

/**
 * print_i - prints a signed decimal integer.
 *
 * @number: number to be printed
 * Return: no. bytes written.
 */

int print_i(int number)
{
	return (print_d(number));
}
