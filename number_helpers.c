#include "main.h"

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

/**
 * format_integer - format integer
 * @i: The integer
 *
 * Return: integer length
 */
int format_integer(int i)
{
	print_number(i);

	return (digits_count(i));
}
