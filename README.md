# A C File Templates

![Flowchart](https://i.postimg.cc/J0JN0bqm/Screenshot-2025-07-23-222350.jpg)


The _printf() function produces output according to a format string specified by format. It takes a variable number of arguments, with the first argument being a format string that specifies how the subsequent arguments should be formatted and printed.

It uses va_list to handle the variable arguments passed to it.

## A Supported format specifiers:

| Specifier | Description |
| --- | --- |
| %c | Prints a single character. Argument must be of type int. |
| %s | Prints a null-terminated string. Argument must be a const char *. |
| %d | Prints a signed decimal integer. |
| %i | Prints a signed decimal integer. |
| %% | Prints a literal percent sign. |

## Unknown specifiers
If the format specifier is not recognized, it will just print the % character followed by the unknown specifier.

## A Return Value 
As it processes each format specifier or character, _printf keeps track of how many characters have been printed using a length variable.

If the format string ends right after a % without a valid specifier, the function returns -1.
Otherwise, it returns the total number of characters printed and calls va_end to clean up the argument list.

## A Type of Files
| Specifier | Description |
| --- | --- |
| _printf.c | This is where the _printf function is written. It goes through the format string, figures out which specifier is used, and handles each one. It also works with va_list to manage the arguments. |
| printf_specifiers.c | Contains the functions that print things like characters, strings, and integers. Each function handles one type of format specifier (like %c, %s, %d, or %i).|
| main.h | The header file. It has the function prototypes and the includes needed for the project. |
| main.c | Used to test _printf. It has a main function with different _printf calls to check if everything works right compared to the regular printf. |
| _putchar.c | This file has the _putchar function. It uses the write system call to print one character to the standard output. It’s used by other functions in the project to print characters without using the standard library. |

## A Naming Conventions & Coding Style

### Prefixes and Functions

All custom functions use the _ prefix to avoid conflicts with standard library functions (e.g., _printf, _putchar).
Helper functions for specifiers are named based on what they handle, like print_char, print_string, or print_int.
Function and variable names are written in lowercase with underscores for readability.
The code follows the Betty coding style used in Holberton projects (consistent indentation, clear structure, and proper documentation).
Header files use include guards to prevent multiple inclusion.

### A Macros

#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_char(char character);
int print_string(const char *string);
int print_d(int number);
int print_i(int number);

#endif /* MAIN_H */

### A Variables

int c;
int s;
int len = 0;
int len;
int len2;
unsigned int ui;
void *addr;
va_list args;
int length = 0;

## A Errors
Returns -1 if the format string ends with % and no specifier after it.

### Examples

len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");

ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;

_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);

_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);

## A  Author
Made by Holberton Cohort 27 students:
Crystal Chiam, Grâce Kayembe & Thannie Phan
