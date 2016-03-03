/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:39 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/03 18:12:49 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_list(t_list *elem)
{
	ft_putstr(elem->content);
	ft_putstr("\n");
}

void	print_linked(t_list *elem)
{
	t_room_link *link;

	link = (t_room_link *)elem->content;
	ft_putstr("Room : ");
	ft_putstr(link->room);
	ft_putstr(" linked to room :\n");
	ft_lstiter(link->linked, print_list);
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
	ft_putstr("Room linked :\n");
	ft_lstiter(data->room_links, print_linked);
	ft_putstr("Best Path :\n");
	ft_lstiter(data->best_path->room_path, print_list);
	ft_putnbr(data->best_path->length);
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
	//printf("a\n");
	link_checker(data);
	//printf("b\n");
	path_process(data);
	//printf("c\n");
	ft_lstiter(entry, print_list);
	print_data(data);
//	while (1)
//	{
//	}
	return (0);
}
