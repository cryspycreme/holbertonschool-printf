# C File Templates

The _printf() function produces output according to a format string specified by format. It takes a variable number of arguments, with the first argument being a format string that specifies how the subsequent arguments should be formatted and printed.

It uses va_list to handle the variable arguments passed to it.

## Supported format specifiers:

| Specifier | Description |
| --- | --- |
| %c | Prints a single character. Argument must be of type int. |
| %s | Prints a null-terminated string. Argument must be a const char *. |
| %d | Prints a signed decimal integer. |
| %i | Prints a signed decimal integer. |
| %% | Prints a literal percent sign. |

## Unknown specifiers
If the format specifier is not recognized, it will just print the % character followed by the unknown specifier.

## Return Value 
As it processes each format specifier or character, _printf keeps track of how many characters have been printed using a length variable.

If the format string ends right after a % without a valid specifier, the function returns -1.
Otherwise, it returns the total number of characters printed and calls va_end to clean up the argument list.

## Type of Files
| Specifier | Description |
| --- | --- |
| _printf.c | This is where the _printf function is written. It goes through the format string, figures out which specifier is used, and handles each one. It also works with va_list to manage the arguments. |
| printf_specifiers.c | Contains the functions that print things like characters, strings, and integers. Each function handles one type of format specifier (like %c, %s, %d, or %i).|
| main.h | The header file. It has the function prototypes and the includes needed for the project. |
| main.c | Used to test _printf. It has a main function with different _printf calls to check if everything works right compared to the regular printf. |
| _putchar.c | This file has the _putchar function. It uses the write system call to print one character to the standard output. It’s used by other functions in the project to print characters without using the standard library. |

## Naming Conventions & Coding Style

### Prefixes and Functions

All custom functions use the _ prefix to avoid conflicts with standard library functions (e.g., _printf, _putchar).
Helper functions for specifiers are named based on what they handle, like print_char, print_string, or print_int.
Function and variable names are written in lowercase with underscores for readability.
The code follows the Betty coding style used in Holberton projects (consistent indentation, clear structure, and proper documentation).
Header files use include guards to prevent multiple inclusion.

## FlowChart
![Flowchart](https://i.postimg.cc/NfVhj1py/Screenshot-2025-07-23-222350.jpg)

## Project Requirements

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation; do not push your own main.c file. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called main.h
* Don’t forget to push your header file
* All your header files should be include guarded

### Compile
Use the following command to compile
```
$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c
```
### Authorized functions and Macros

* write (man 2 write)
* malloc (man 3 malloc)
* free (man 3 free)
* va_start (man 3 va_start)
* va_end (man 3 va_end)
* va_copy (man 3 va_copy)
* va_arg (man 3 va_arg)

## Project Tasks
### 0. Write a function that produces output according to a format.

* Prototype: int _printf(const char *format, ...);
* Returns: the number of characters printed (excluding the null byte used to end output to strings)
* write output to stdout, the standard output stream
* format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
* c
* s
* %
* You don’t have to reproduce the buffer handling of the C library printf function
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers

### 1. Handle the following conversion specifiers:
* d
* i
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers

### Prototype Functions 
```
#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_char(char character);
int print_string(const char *string);
int print_d(int number);
int print_i(int number);

#endif /* MAIN_H */
```
### Variables
```
int c;
int s;
int len = 0;
int len;
int len2;
unsigned int ui;
void *addr;
va_list args;
int length = 0;
```
## Errors
Returns -1 if the format string ends with % and no specifier after it.

### Examples
```
len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");

ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;

_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);

_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);
```
## Author
Made by Holberton Cohort 27 students:
Crystal Chiam, Grâce Kayembe & Thannie Phan
