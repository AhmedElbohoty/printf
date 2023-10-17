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
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{

		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_str(va_arg(args, char *));
			else if (*format == 'i')
				count += print_int(va_arg(args, int));
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
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
