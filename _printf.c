#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

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
	int i = 0, char_count = 0, d;
	char c;
	va_list args;

	if (format == NULL)
		return (1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			c = format[i + 1];
			if (c == 'c')
				_putchar(va_arg(args, int));
			if (c == 'i' || c == 'd')
			{
				d = va_arg(args, int);
				char_count += digits_count(d);
				print_number(d);
			}

			if (c == 's')
				char_count += format_str(va_arg(args, char *));

			if (c == '%')
				_putchar('%');
			i++;
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}

		i++;
	}
	va_end(args);

	return (char_count);
}
