#include <unistd.h>

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
 * handle_unkown_sp - Check for unknow specifier
 * @sp: specifier
 *
 * Return: - If unknow specifier, return (-1).
 *         - Else, return (0).
 */
int handle_unkown_sp(char sp)
{
	if (sp == ' ' || sp == '\0')
		return (-1);

	return (0);
}

/**
 * digits_count - count the number of digits
 * @n: The number
 *
 * Return: the number of digits
 */
int digits_count(int n)
{
	int count = 0;

	while (n != 0)
	{
		n = n / 10;
		count++;
	}

	return (count);
}
