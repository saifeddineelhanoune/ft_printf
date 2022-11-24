#include"ft_printf.h"

void ft_putnbr(int nb, int *count)
{
	if (nb == INT_MIN)
		ft_putstr("-2147483648", count);
	else if (nb < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(nb * -1, count);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, count);
		ft_putchar((nb % 10) + 48, count);
	}
	else
		ft_putchar(nb + 48, count);
}

void ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void ft_putstr(char *str, int *count)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(*str, count);
			str++;
		}
	}
	else	
		ft_putstr("(null)", count);
}

void ft_converthexbase(unsigned long n, char *base, int *count)
{
    if (n >= 16)
	{
		ft_converthexbase(n / 16, base, count);
		ft_putchar(base[n % 16], count);
	}
	else
		ft_putchar(base[n % 16], count);
}

void ft_convertdecbase(unsigned int n, char *base, int *count)
{
    if (n >= 10)
	{
		ft_convertdecbase(n / 10, base, count);
		ft_putchar(base[n % 10], count);
	}
	else
		ft_putchar(base[n % 10], count);
}

void ft_check_format(char specifier, va_list args, int *count)
{
	if (specifier == 'p')
	{
		ft_putstr("0x", count);
		ft_converthexbase(va_arg(args, unsigned long), LOWERHEXBASE, count);
	}
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (specifier == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (specifier == 'x')
		ft_converthexbase(va_arg(args, unsigned int), LOWERHEXBASE, count);
	else if (specifier == 'X')
		ft_converthexbase(va_arg(args, unsigned int), UPPERHEXBASE, count);
	else if (specifier == 'u')
		ft_convertdecbase(va_arg(args, unsigned int), DECIMALBASE, count);
	else
		ft_putchar(specifier, count);
}
