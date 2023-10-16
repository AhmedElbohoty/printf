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
	int i = 0, len = 0, d;
	char c;
	va_list ap;

	if (format == NULL)
		exit(1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			c = format[i + 1];
			if (c == 'c')
				_putchar(va_arg(ap, int));
			if (c == 'i' || c == 'd')
			{
				d = va_arg(ap, int);
				len += digits_count(d);
				print_number(d);
			}

			if (c == 's')
				len += format_str(va_arg(ap, char *));

			if (c == '%')
				_putchar('%');
			i++;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}

		i++;
	}
	va_end(ap);

	return (len);
}

