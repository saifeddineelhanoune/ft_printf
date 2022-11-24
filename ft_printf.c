#include"ft_printf.h"

int ft_printf(const char *format, ...)
{

	va_list args;
	int i;
	int count;

	i = 0;
	count = 0;
	if (format)
	{
		va_start(args, format);
		while (format[i])
		{
			if (format[i] == '%' && format[i + 1])
				ft_check_format(format[++i], args, &count);
			else if(format[i] != '%')
				ft_putchar(format[i], &count);

			i++;
		}
		va_end(args);
		return count;
	}
	return -1;
}
int main()
{
	char *s = "%";
	printf("\n%d\n", ft_printf(s, 18));
	printf("\n%d\n", printf(s, 18));
	return (0);
}