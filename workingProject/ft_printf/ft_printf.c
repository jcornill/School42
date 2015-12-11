/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/11 00:10:55 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_list *elem)
{
	ft_putstr(elem->content);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	t_list		*list;
	size_t		val;
	char		*content;
	int			compteur;

	compteur = 0;
	list = NULL;
	va_start(args, str);
	while (str[compteur] != '\0')
	{
		str = &str[compteur];
		val = ft_strlenstr(str, "%s") - 1;
		compteur += val;
		content = ft_memdup(str, val);
		content[val] = 0;
		ft_lstadd(&list, ft_lstnew(content, val));
		if (val != ft_strlen(str))
		{
			content = va_arg(args, char *);
			ft_lstpush(&list, ft_lstnew(content, ft_strlen(content)));
		}
		
	}
	ft_lstiter(list, &print_arg);
	va_end(args);
	return (0);
}
