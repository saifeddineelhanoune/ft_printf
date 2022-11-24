#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define INT_MIN -2147483648
#define UPPERHEXBASE "0123456789ABCDEF"
#define LOWERHEXBASE "0123456789abcdef"
#define DECIMALBASE  "0123456789"

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
void ft_converthexbase(unsigned int n, char *base);
void ft_convertdecbase(unsigned long n, char *base);
void ft_check_format(const char specifier, va_list args);



#endif