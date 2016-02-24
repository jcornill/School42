/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:32:11 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/23 16:32:15 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_list(t_list *elem)
{
	ft_putstr(elem->content);
	ft_putstr("\n");
}

void	print_link(t_list *elem)
{
	t_link	*link;

	link = (t_link *)elem->content;
	printf("%p\n", elem->content);
	ft_putstr(link->room_a);
	ft_putstr(" : ");
	ft_putstr(link->room_b);
	ft_putstr("\n");
}

void	err_exit(int id)
{
	ft_putstr_fd("ERROR : ", 2);
	ft_putnbr_fd(id, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int		main(void)
{
	t_data	*data;

	data = check_entry(0, 0);
	ft_lstiter(data->links, print_link);
	return (0);
}
