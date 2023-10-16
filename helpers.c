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
