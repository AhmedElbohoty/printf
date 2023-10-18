#include <stdarg.h>

#ifndef MAIN_HEADER
#define MAIN_HEADER

/**
 * struct formatter - match the conversion specifiers for printf
 * @sp: type char pointer of the specifier
 * @func: type pointer to function for the specifier
 *
 */
typedef struct formatter
{
    char *sp;
    int (*func)(va_list args);
} formatter;

int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
void print_number(int n);
int print_str(va_list args);
int digits_count(int n);
int print_char(va_list args);
int print_int(va_list args);
int print_binary(va_list args);

#endif /* #ifndef MAIN_HEADER */
