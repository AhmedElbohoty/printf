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
