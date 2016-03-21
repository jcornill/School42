/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:53 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/21 12:42:55 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			c_nbants(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_strlen(str) >= 10 && ft_strcmp("2147483647", str) < 0)
		err_exit(6, "Number of ants to high (above int) !");
	if (ft_atoi(str) == 0)
		err_exit(9, "Need at leats one ant !");
	return (ft_atoi(str));
}

static int			check_link(char *room_a, char *room_b, t_list **rooms_name)
{
	t_list	*begin;
	int		find_room;

	find_room = 0;
	begin = *rooms_name;
	if (begin == NULL)
		err_exit(7, "Try creating link with no room created !");
	if (ft_strcmp(begin->content, room_a) == 0)
		find_room++;
	else if (ft_strcmp(begin->content, room_b) == 0)
		find_room++;
	while (begin->next != NULL)
	{
		begin = begin->next;
		if (ft_strcmp(begin->content, room_a) == 0)
			find_room++;
		else if (ft_strcmp(begin->content, room_b) == 0)
			find_room++;
	}
	if (find_room == 2)
		return (1);
	return (0);
}

static t_link		*create_link(char *str, t_list **rooms_name)
{
	int		i;
	char	*room_a;
	char	*room_b;
	t_link	*ret;

	room_a = 0;
	room_b = 0;
	ret = ft_memalloc(sizeof(t_link));
	i = -1;
	if (str[0] == '#')
		return (0);
	while (str[++i])
		if (str[i] == '-')
		{
			room_a = ft_strsub(str, 0, i);
			i++;
			room_b = ft_strsub(str, i, ft_strlen(str));
			if (!check_link(room_a, room_b, rooms_name))
				err_exit(8, "Link with no created room !");
			ret->room_a = room_a;
			ret->room_b = room_b;
			return (ret);
		}
	return (0);
}

static char			*check_room(char *str, t_data *data, int nb_sp, int i)
{
	char		*ret;
	static int	room = 0;

	ret = 0;
	if (ft_strcmp(str, "##start") == 0)
		room += 10;
	else if (ft_strcmp(str, "##end") == 0)
		room -= 5;
	if (str[i] == 'L' || str[i] == '#')
		return (NULL);
	while (str[i])
	{
		if (str[i] == '-')
			return (NULL);
		if (str[i] == ' ')
			nb_sp++;
		if (nb_sp == 1 && ret == 0)
			ret = ft_strsub(str, 0, i);
		if (nb_sp > 0 && (!ft_isdigit(str[i]) && str[i] != ' '))
			err_exit(5, "Inccorect room coord");
		i++;
	}
	room = set_s_e_room(nb_sp, room, data, ret);
	check_room_2(ret, data, str);
	return (ret);
}

t_data				*check_entry(char *str, t_list **entry)
{
	char	*room;
	t_data	*data;

	data = ft_memalloc(sizeof(t_data));
	data->nb_ants = -1;
	data->rooms_name = 0;
	data->links = 0;
	while (get_next_line(0, &str))
	{
		if (str[0] == 0)
			break ;
		if (c_nbants(str) > 0 && (data->nb_ants *= c_nbants(str) * -1) < 0)
			err_exit(1, "Multiple ants number !");
		room = check_room(str, data, 0, 0);
		if (room != 0)
			ft_lstadd(&data->rooms_name, ft_lstnew(room, ft_strlen(room)));
		ft_lstpush(&(*entry), ft_lstnew(str, ft_strlen(str)));
		if (create_link(str, &data->rooms_name) != 0)
			ft_lstpush(&data->links,
			ft_lstnew(create_link(str, &data->rooms_name), sizeof(t_link)));
	}
	if (data->nb_ants < 0 || data->start_room == 0
		|| data->end_room == 0 || data->rooms_name == 0)
		err_exit(3, "No enought data !");
	return (data);
}
