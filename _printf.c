#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

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
	int ch, char_count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				ch = va_arg(args, int);
				write(1, &ch, 1);
				char_count++;
			}
			else if (*format == 's')
				char_count += format_str(va_arg(args, char *));
			else if (*format == '%')
			{
				write(1, format, 1);
				char_count++;
			}
		}
		format++;
	}
	va_end(args);

	return (char_count);
}
