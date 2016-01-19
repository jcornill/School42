#include "ft_printf.h"

int		print_arg_str(char *str, char param)
{
	if (param == 's')
		return (ft_putstrprintf(str));
	else if (param == '%')
		return (write(1, "%", 1));
	return (0);
}

int		print_arg_nb(long nb, char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u')
		return (ft_putnbr_long(nb));
	else if (c == 'p')
		return (ft_putaddr(nb));
	else if (c == 'o')
		return (ft_putnbr_base(nb, 8, 0));
	else if (c == 'b')
		return (ft_putnbr_base(nb, 2, 0));
	else if (c == 'x')
		return (ft_putnbr_base(nb, 16, 0));
	else if (c == 'X')
		return (ft_putnbr_base_long(nb, 16, 1));
	return (0);
}

int		print_arg_unb(unsigned long nb, char c)
{
	if (c == 'O' || c == 'o')
		return (ft_putnbr_base_long(nb, 8, 0));
	else if (c == 'b')
		return (ft_putnbr_base_long(nb, 2, 0));
	else if (c == 'U' || c == 'd' || c == 'D' || c == 'i' || c == 'u')
		return (ft_putnbr_ulong(nb));
	else if (c == 'x')
		return (ft_putnbr_base_long(nb, 16, 0));
	else if (c == 'X')
		return (ft_putnbr_base_long(nb, 16, 1));
	return (0);
}