/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:38:06 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/01 17:59:16 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_grid(char *str, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->grid->heigth && get_next_line(0, &str) > 0)
	{
		if (ft_strlen(str) > 4)
			str = &str[4];
		i = 0;
		while (str[i])
		{
			if (str[i] == '.')
				data->grid->grid[i + j * data->grid->width] = 0;
			else if (str[i] == 'X' || str[i] == 'x')
				data->grid->grid[i + j * data->grid->width] = 2;
			else if (str[i] == 'O' || str[i] == 'o')
				data->grid->grid[i + j * data->grid->width] = 1;
			i++;
		}
		j++;
	}
}

t_grid	*init_grid(char *str)
{
	int		i;
	t_grid	*grid;

	i = 0;
	grid = ft_memalloc(sizeof(t_grid));
	while (!ft_isdigit(str[i]))
		i++;
	grid->heigth = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	i++;
	grid->width = ft_atoi(&str[i]);
	grid->grid = ft_memalloc(grid->width * grid->heigth + 1);
	return (grid);
}

void	get_player(char *str, t_data *data)
{
	if (ft_strlen(str) > 15)
	{
		str[11] = 0;
		if (ft_strcmp(str, "$$$ exec p2") == 0)
			data->player = 2;
		else if (ft_strcmp(str, "$$$ exec p1") == 0)
			data->player = 1;
	}
}

t_data	*process_input(char *str, int player)
{
	t_data	*data;
	int		temp;

	temp = 0;
	data = ft_memalloc(sizeof(t_data));
	data->player = player;
	if (data->player == 0)
	{
		get_player(str, data);
		temp = 1;
	}
	if (temp == 1)
	{
		if (get_next_line(0, &str) > 0)
			data->grid = init_grid(str);
	}
	else
		data->grid = init_grid(str);
	get_next_line(0, &str);
	set_grid(str, data);
	data->piece = init_piece(str, data);
	return (data);
}
