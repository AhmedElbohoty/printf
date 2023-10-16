#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: - If error, return -1.
 *         - Else, return 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to string
 *
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	if (*s == '\0')
		return (len);

	len = 1 + _strlen(s + 1);

	return (len);
}

/**
 * print_string - prints string
 * @str: The string
 *
 * Return: the pointer to string
 */
char *print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (str);
}

/**
 * print_number - prints long integer using putchar
 * @n: The number to be printed
 *
 * Return: Void
 */
void print_number(int n)
{
	unsigned int i;

	if (n < 0)
	{
		_putchar('-');
		i = -n;
	}
	else
	{
		i = n;
	}

	if (i / 10)
		print_number(i / 10);

	_putchar(i % 10 + '0');
}

/**
 * format_str - format string
 * @str: The string
 *
 * Return: string length
 */
int format_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i + 1);
}
