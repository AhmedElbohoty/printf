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
 * print_int - format integer
 * @args: arguments
 *
 * Return: integer length
 */
int print_int(va_list args)
{
	char buff[32];
	int len = 0, i = 0, j, numb;

	numb = va_arg(args, int);
	if (numb < 0)
	{
		write(1, "-", 1);
		len++;
		numb = -numb;
	}

	do {
		buff[i++] = '0' + (numb % 10);
		numb /= 10;
		len++;
	} while (numb > 0);

	for (j = i - 1; j >= 0; j--)
		write(1, &buff[j], 1);

	return (len);
}

/**
 * print_binary - convert integer to binary and print it.
 * @args: arguments
 *
 * Return: binary length
 */
int print_binary(va_list args)
{
	int buff[32], i = 0, j, numb;

	numb = va_arg(args, int);
	if (numb == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (numb > 0)
	{
		buff[i++] = numb % 2;
		numb /= 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (buff[j] == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
	}

	return (i);
}

/**
 * print_hex - convert integer to hexadecimal and print it.
 * @args: arguments
 *
 * Return: hexadecimal length
 */
int print_hex(va_list args)
{
	char buff[100], c;
	unsigned int q, r, d;
	int i, j = 0;

	d = va_arg(args, unsigned int);

	q = d;
	while (q != 0)
	{
		r = q % 16;
		if (r < 10)
			buff[j++] = 48 + r;
		else
			buff[j++] = 55 + r;
		q = q / 16;
	}

	for (i = j; i >= 0; i--)
	{
		c = buff[i];
		write(1, &c, 1);
	}

	return (j);
}
