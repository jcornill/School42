/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:53 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/29 10:36:02 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					c_nbants(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '#')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > 2147483647)
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
		return (0);
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
	if (str[0] == '#')
		return (0);
	if (!(ret = ft_memalloc(sizeof(t_link))))
		err_exit(-1, "Malloc error");
	i = -1;
	while (str[++i])
		if (str[i] == '-')
		{
			room_a = ft_strsub(str, 0, i);
			i++;
			room_b = ft_strsub(str, i, ft_strlen(str));
			i--;
			if (!check_link(room_a, room_b, rooms_name))
				continue ;
			ret->room_a = room_a;
			ret->room_b = room_b;
			return (ret);
		}
	return ((t_link *)1);
}

static char			*check_room(char *str, t_data *data, int i)
{
	char		*ret;
	static int	room = 0;

	if ((ret = 0) == 0 && ft_strcmp(str, "##start") == 0)
		room += 10;
	else if (ft_strcmp(str, "##end") == 0)
		room -= 5;
	if (str[0] == 'L' || str[0] == '#')
		return (NULL);
	while ((ft_isdigit(str[i]) || str[i] == '-'))
		if (i-- < 0)
			return (0);
	if (str[i--] != ' ')
		return (0);
	while ((ft_isdigit(str[i]) || str[i] == '-') && i >= 0)
		i--;
	if (i <= 0)
		return (0);
	if (str[i--] != ' ')
		return ((char *)1);
	ret = ft_strsub(str, 0, i + 1);
	room = set_s_e_room(room, data, ret);
	if (check_room_2(ret, data) == 0)
		return ((char *)1);
	return (ret);
}

t_data				*check_entry(char *str, t_list **entry)
{
	char	*room;
	t_data	*data;

	data = init_data(str, entry);
	while (get_next_line(0, &str) > 0)
	{
		if (str[0] == 0)
			break ;
		if ((room = check_room(str, data, ft_strlen(str) - 1)) == 0)
			if (create_link(str, &data->rooms_name) != 0 &&
				create_link(str, &data->rooms_name) != (t_link *)1)
				ft_lstpush(&data->links, ft_lstnew(
				create_link(str, &data->rooms_name), sizeof(t_link)));
			else if (create_link(str, &data->rooms_name) == (t_link *)1)
				break ;
			else;
		else if (room != (char *)1)
			ft_lstadd(&data->rooms_name, ft_lstnew(room, ft_strlen(room)));
		else
			break ;
		ft_lstpush(&(*entry), ft_lstnew(str, ft_strlen(str)));
	}
	if (data->start_room == 0 || data->end_room == 0 || data->rooms_name == 0)
		err_exit(3, "No enought data !");
	return (data);
}
