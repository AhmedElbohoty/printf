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
	int i = 0, len = 0;
	va_list ap;

	if (format == NULL)
		exit(1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				_putchar(va_arg(ap, int));
				break;
			case 'i':
				print_number(va_arg(ap, int));
				break;
			case 'd':
				print_number(va_arg(ap, int));
				break;
			case 's':
				len += format_str(va_arg(ap, char *)) - 1;
				break;
			case '%':
				_putchar('%');
				break;

			default:
				break;
			}
			i++;
		}
		else
			_putchar(format[i]);

		len++;
		i++;
	}
	va_end(ap);

	return (len);
}
