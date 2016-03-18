/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:39 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/18 14:25:52 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_list(t_list *elem)
{
	ft_putstr(elem->content);
	ft_putchar('\n');
}

void	delete_list(void *cont, size_t size)
{
	free(cont);
	cont = 0;
	size = 0;
}

void	free_data(t_data *data)
{
	ft_lstdel(&data->rooms_name, delete_list);
	ft_lstdel(&data->links, delete_list);
	ft_lstdel(&data->room_links, delete_list);
	free(data->best_path);
	ft_lstdel(&data->lst_room, delete_list);
	ft_lstdel(&data->lst_ants, delete_list);
	free(data);
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
	link_checker(data);
	path_process(data);
	ft_lstiter(entry, print_list);
	ft_putchar('\n');
	ants_mover(data);
	ft_lstdel(&entry, delete_list);
	free_data(data);
	return (0);
}
