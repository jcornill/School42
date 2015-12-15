/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/15 19:45:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg(char *str)
{
	if (str[0] == 's')
		return ("s");
	else if (str[0] == 'S')
		return ("S");
	return (0);
}

void	print_arg(void *str, char *param)
{
	if (param == "s")
		write(1, str, ft_strlen(str));
	else if (param == "S")
	{
		write(1, str, 2);
	}
}

int		process_input(char *str, char **param)
{
	char	*result;
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
	char		*content;
	int			compteur;
	int			len;
	char		*param;
	
	compteur = 0;
	va_start(args, str);
	len = ft_strlen(str);
	param = NULL;
	while (compteur < len)
	{
		if (compteur != 0)
			str = &str[val + 2];
		val = process_input(str, &param);
		if (param != NULL)
			compteur += val + ft_strlen(param) + 1;
		else
			compteur += val + 2;
		write(1, str, val);
		if (val != ft_strlen(str))
			print_arg(va_arg(args, void *), param);

	}
	va_end(args);
	return (0);
}
