#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define INT_MIN -2147483648
#define UPPERHEXBASE "0123456789ABCDEF"
#define LOWERHEXBASE "0123456789abcdef"
#define DECIMALBASE  "0123456789"

int ft_printf(const char *format, ...);
void ft_putchar(char c, int *count);
void ft_putstr(char *str, int *count);
void ft_putnbr(int nb, int *count);
void ft_converthexbase(unsigned long n, char *base, int *count);
void ft_convertdecbase(unsigned int n, char *base, int *count);
void ft_check_format(const char specifier, va_list args, int *count);

#endif