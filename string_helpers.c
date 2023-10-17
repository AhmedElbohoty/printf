#include <unistd.h>
#include <stdio.h>

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
 * @str: The string
 *
 * Return: string length
 */
int print_str(char *str)
{
	int len;

	len = _strlen(str);
	write(1, str, len);

	return (len);
}

/**
 * print_char - format character
 * @c: The character
 *
 * Return: character length
 */
int print_char(int c)
{
	write(1, &c, 1);

	return (1);
}
