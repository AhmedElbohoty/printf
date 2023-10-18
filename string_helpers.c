#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _strlen - returns the length of a string
 * @s: pointer to string
 *
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len++] != '\0')
		len++;

	return (len);
}

/**
 * print_str - format string
 * @args: arguments
 *
 * Return: string length
 */
int print_str(va_list args)
{
	int len;
	char *str;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	len = _strlen(str);
	write(1, str, len);

	return (len);
}

/**
 * print_char - format character
 * @args: arguments
 *
 * Return: character length
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);

	return (1);
}
