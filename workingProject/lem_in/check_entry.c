/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:46:48 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/23 16:46:50 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_nbants(char *str)
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
		err_exit();
	return (ft_atoi(str));
}
/*
static void		check_link(char *str)
{
	int		i;

	i = 0;
	if (str[i] != 'L')
		return ;
	i++;
	while (str[i])
	{
		
		i++;
	}
}
*/
static char		*check_room(char *str)
{
	int		i;
	int		nb_space;
	char	*ret;

	ret = 0;
	i = 0;
	nb_space = 0;
	if (str[i] == 'L' || str[i] == '#')
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			nb_space++;
		if (nb_space == 1 && ret == 0)
			ret = ft_strsub(str, 0, i);
		if (nb_space > 0 && (!ft_isdigit(str[i]) && str[i] != ' '))
			err_exit();
		i++;
	}
	if (nb_space > 2)
		err_exit();
	return (ret);
}

int				check_entry(char *str)
{
	int		nb_ants;

	nb_ants = -1;
	while (get_next_line(0, &str))
	{
		printf("%s\n", str);
		if (check_nbants(str) > 0 && (nb_ants *= check_nbants(str) * -1) < 0)
			err_exit();
		printf("%s\n", check_room(str));
	}
	if (nb_ants < 0)
		err_exit();
	return (1);
}
