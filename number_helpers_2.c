#include "main.h"
#include <stdio.h>
#include <unistd.h>

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
        if (c >= 'A' && c <= 'Z')
            c += 32;
        write(1, &c, 1);
    }

    return (j);
}
