/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:39 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/19 16:02:31 by jcornill         ###   ########.fr       */
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
	id = 0;
	ft_putstr_fd("ERROR : ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int		main(void)
{
	t_data	*data;
	t_list	*entry;

	entry = 0;
	data = check_entry(0, &entry);
	printf("%s\n", "1");
	link_checker(data);
	printf("%s\n", "2");
	path_process(data);
	printf("%s\n", "3");
	ft_lstiter(entry, print_list);
	ft_putchar('\n');
	printf("%s\n", "4");
	if (data->start_room == data->end_room)
		ants_mover(data);
	printf("%s\n", "5");
	ft_lstdel(&entry, delete_list);
	free_data(data);
	return (0);
}
