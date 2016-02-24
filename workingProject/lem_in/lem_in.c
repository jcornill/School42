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
	ft_putstr(link->room_a);
	ft_putstr("-");
	ft_putstr(link->room_b);
	ft_putstr("\n");
}

void	print_data(t_data *data)
{
	ft_putstr("==Map data==\n");
	ft_putstr("Ants : ");
	ft_putnbr(data->nb_ants);
	ft_putstr("\nStart room : ");
	ft_putstr(data->start_room);
	ft_putstr("\nEnd room : ");
	ft_putstr(data->end_room);
	ft_putstr("\nRooms list :\n");
	ft_lstiter(data->rooms_name, print_list);
	ft_putstr("Links list :\n");
	ft_lstiter(data->links, print_link);
}

void	err_exit(int id, char *err)
{
	ft_putstr_fd("ERROR : ", 2);
	ft_putnbr_fd(id, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(err, 2);
	ft_putstr("\n");
	exit(1);
}

int		main(void)
{
	t_data	*data;
	t_list	*entry;

	entry = 0;
	data = check_entry(0, &entry);
	ft_lstiter(data->links, print_link);
	ft_lstiter(entry, print_list);
	print_data(data);
	return (0);
}
