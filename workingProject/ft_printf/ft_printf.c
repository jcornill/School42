/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 20:03:41 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg(char *str)
{
	if (str[0] != '%')
		return (0);
	if (str[1] == 's')
		return ("%s");
	else if (str[1] == 'd')
		return ("%d");
	else if (str[1] == 'p')
		return ("%p");
	return (0);
}

int		print_arg(void *str, char *param)
{
	if (!ft_strcmp("%s", param))
		return (ft_putstrprintf(str));
	if (!ft_strcmp("%d", param))
		return (ft_putnbr_long((int)str));
	if (!ft_strcmp("%p", param))
		return (ft_putaddr((long)&str))
	return (0);
}

int		process_input(char *str, char **param)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if (((*param) = get_arg(&str[len])) != 0)
			return (ft_strlenstr(str, (*param)));
		len++;
	}
	return (ft_strlen(str));
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	size_t		val;
	int			compteur;
	int			len;
	char		*param;
	int			written_char;
	
	compteur = 0;
	written_char = 0;
	va_start(args, str);
	len = ft_strlen(str);
	param = NULL;
	while (compteur < len)
	{
		if (compteur != 0)
			str = &str[val + 2];
		val = process_input(str, &param);
		if (param != NULL)
			compteur += val + ft_strlen(param);
		else
			compteur += val + 2;
		written_char += val;
		write(1, str, val);
		if (val != ft_strlen(str))
			written_char += print_arg(va_arg(args, void *), param);

	}
	va_end(args);
	return (written_char);
}
