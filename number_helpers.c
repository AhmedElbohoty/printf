#include "main.h"
#include <stdio.h>
#include <unistd.h>

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
 * print_int - format integer
 * @numb: The integer
 *
 * Return: integer length
 */
int print_int(int numb)
{
	char buff[32];
	int len = 0, i = 0;

	if (numb < 0)
	{
		write(1, "-", 1);
		len++;
		numb = -numb;
	}

	do
	{
		buff[i++] = '0' + (numb % 10);
		numb /= 10;
		len++;
	} while (numb > 0);

	write(1, &buff, len);

	return (len);
}
