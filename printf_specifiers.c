#include "main.h"
#include <string.h> /*strlen*/
#include <unistd.h> /*write*/

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
