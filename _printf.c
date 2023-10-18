#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Produces output according to a format
 *           and write the output to stdout
 * @format: is a character string and it is
 *          composed of zero or more directives
 *
 * Return: the number of characters printed
 *         (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0, j = 4;
	va_list args;
	formatter f[] = {
		{"%c", print_char}, {"%s", print_str}, {"%i", print_int},
		{"%d", print_int}, {"%b", print_binary}};

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}

			while (j >= 0)
			{
				if (f[j].sp[1] == *format)
					count += f[j].func(args);
				j--;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
