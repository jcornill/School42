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

static int		check_link(char *str)
{
	
}

int				check_entry(int argc, char **argv)
{
	int		i;
	int		nb_ants;

	i = 1;
	nb_ants = -1;
	while (i < argc)
	{
		if (check_nbants(argv[i]) > 0 && (nb_ants *= check_nbants(argv[i]) * -1) < 0)
			err_exit();
	}
	if (nb_ants < 0)
		err_exit();
}
