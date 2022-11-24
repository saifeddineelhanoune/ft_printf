#include"ft_printf.h"

int ft_printf(const char *format, ...)
{

	va_list args;
	int i;

	i = 0;
	va_start(args, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%' && format[i + 1])
				ft_check_format(format[i],args);
			i++;
		}
	}
	va_end(args);
	return 0;
}
int main()
{
	int nb = 0;
	ft_printf("hello you should print an integer %d", nb);
	return (0);
}