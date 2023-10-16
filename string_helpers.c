#include <unistd.h>

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
 * format_str - format string
 * @str: The string
 *
 * Return: string length
 */
int format_str(char *str)
{
	int len;

	len = _strlen(str);
	write(1, &str, len);

	return (len);
}
