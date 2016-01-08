/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/19 19:41:30 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_arg_str(char *str, char param)
{
	if (param == 's')
		return (ft_putstrprintf(str));
	else if (param == '%')
		return (write(1, "%", 1));
	return (0);
}

int		print_arg_nb(long nb, char param)
{
	if (param == 'd')
		return (ft_putnbr_long(nb));
	else if (param == 'p')
		return (ft_putaddr(nb));
	return (0);
}

int		process_arg(void *content, char *param, char convertion)
{
	char	*str;
	int		number;

	str = 0;
	number = 0;
	if (convertion == 's' || convertion == '%')
	{
		str = (char *)content;
		return (print_arg_str(str, convertion));
	}
	else if (convertion == 'd')
	{
		number = (int)content;
		number = (long)content;
		return (print_arg_nb(number, convertion));
	}
	else if (convertion == 'p')
	{
		number = (long)content;
		return (print_arg_nb(number, convertion));
	}
	return (0);
}

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

char	*search_convertion(char *s)
{
	char	*param;
	int		i;

	i = 1;
	while (s[i])
	{
		if (s[i] == 's' || s[i] == 'd' || s[i] == '%')
		{
			param = ft_strnew(i + 1);
			param[0] = '%';
			ft_strncpy(&param[1], &s[1], i);
			//write(1, param, ft_strlen(param));
			return (param);
		}
		if (s[i] == '#' || s[i] == '0' || s[i] == '-' || s[i] == '+'
			|| s[i] == ' ' || s[i] == 'l' || s[i] == 'h')
			i++;
		else
			break ;
	}
	param = ft_strnew(i + 1);
	param[0] = '%';
	if (i > 1)
		ft_strncpy(&param[1], &s[i - 1], i - 1);
	return (param);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	size_t		val;
	int			i;
	int			written_char;
	char		*param;

	i = 0;
	written_char = 0;
	va_start(args, str);
	param = NULL;
	while (str[i])
	{
		if (str[i] == '%')
			param = search_convertion(&str[i]);
		else
			param = NULL;
		if (param != NULL)
		{
			if (ft_strlen(param) > 1)
			{
//				write(1, param, ft_strlen(param));
//				ft_putchar(param[ft_strlen(param) - 1]);
				if (param[ft_strlen(param) - 1] != '%')
					written_char += process_arg(va_arg(args, void *), param, param[ft_strlen(param) - 1]);
				else
					written_char += write(1, "%", 1);
				i += ft_strlen(param) - 1;
			}	
		}
		else
			written_char += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (written_char);
}
