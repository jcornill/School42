/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/11 19:29:22 by jcornill         ###   ########.fr       */
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
	int			len;
	t_param		stock;
	
	compteur = 0;
	list = NULL;
	va_start(args, str);
	len = ft_strlen(str);
	while (compteur < len)
	{
		printf(":%s: ", str);
		if (compteur != 0)
			str = &str[val + 2];
		printf("====> :%s:\n", str);
		val = ft_strlenstr(str, "%s");
		compteur += val + 2;
		stock.size = val + 1;
		content = ft_memdup(str, stock.size);
		content[val] = 0;
		stock.content = content;
		stock.param = "%s";
		ft_lstpush(&list, ft_lstnew(content, stock.size));
		printf("Add : '%s/0':size %zu\n", stock.content, stock.size);
		if (val != ft_strlen(str))
		{
			content = va_arg(args, char *);
			stock.size = ft_strlen(content) + 1;
			stock.content = content;
			stock.param = "%s";
			ft_lstpush(&list, ft_lstnew(content, stock.size));
			printf("Add%%s : '%s/0':size %zu\n", stock.content, stock.size);
		}

	}
	ft_lstiter(list, &print_arg);
	va_end(args);
	return (0);
}
