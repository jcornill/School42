/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/06 00:16:40 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_arg(void *str, char param)
{
	if (param == 's')
		return (ft_putstrprintf(str));
	else if (param == '%')
		return (write(1, "%", 1));
/*
	else if (!ft_strcmp("%d", param) || !ft_strcmp("%i", param))
		return (ft_putnbr_long((int)str));
	else if (!ft_strcmp("%ld", param) || !ft_strcmp("%li", param) || !ft_strcmp("%lld", param) || !ft_strcmp("%lli", param))
		return (ft_putnbr_long((long)str));
	else if (!ft_strcmp("%p", param))
		return (ft_putaddr((long)str));
	else if (!ft_strcmp("%%", param))
		return (ft_putstrprintf("%"));
	else if (!ft_strcmp("%S", param) || !ft_strcmp("%ls", param))
		return (ft_putwchar((wchar_t *)str));
	else if (!ft_strcmp("%D", param))
		return (ft_putnbr_long((long)str));
	else if (!ft_strcmp("%o", param))
		return (ft_putnbr_base((unsigned int)str, 8, 0));
	else if (!ft_strcmp("%O", param) || !ft_strcmp("%lo", param) || !ft_strcmp("%llo", param))
		return (ft_putnbr_base_long((unsigned long)str, 8, 0));
	else if (!ft_strcmp("%u", param))
		return (ft_putnbr_long((unsigned int)str));
	else if (!ft_strcmp("%U", param) || !ft_strcmp("%lu", param) || !ft_strcmp("%llu", param))
		return (ft_putnbr_ulong((unsigned long)str));
	else if (!ft_strcmp("%x", param))
		return (ft_putnbr_base((unsigned int)str, 16, 0));
	else if (!ft_strcmp("%X", param))
		return (ft_putnbr_base_long((unsigned int)str, 16, 1));
	else if (!ft_strcmp("%lx", param))
		return (ft_putnbr_base_long((unsigned long)str, 16, 0));
	else if (!ft_strcmp("%lX", param))
		return (ft_putnbr_base_long((unsigned long)str, 16, 1));
	else if (!ft_strcmp("%c", param))
		return (write(1, &str, 1));
	else if (!ft_strcmp("%C", param) || !ft_strcmp("%lc", param))
		return (ft_putonewchar((wchar_t)str));
	else if (!ft_strcmp("%lO", param))
		return (ft_putnbr_base_long((unsigned long)str, 8, 0) * 0 - 1);
	else if (!ft_strcmp("%lU", param))
		return (ft_putnbr_ulong((unsigned long)str) * 0 - 1);
	else if (!ft_strcmp("%lD", param))
		return (ft_putnbr_long((long)str) * 0 - 1);
*/
	return (0);
}

int		end_param(char c)
{
	if (c == ' ' || c == 'l' || c == 'h')
		return (1);
	return (0);
}

int		process_param(char *str, void *param, int *written_char)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (end_param(str[i]))
		i++;
	if (i == 0 && is_number_param(str[i]))
		number = (int)param;
	if (is_number_param(str[i]))
		(*written_char) += print_arg_number(number, str[i]);
	else
		(*written_char) += print_arg(param, str[i]);
	return (i + 1);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			written_char;
	int			i;

	written_char = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i += process_param(&str[i + 1], va_arg(args, void *), &written_char);
		}
		else
			written_char += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (written_char);
}
