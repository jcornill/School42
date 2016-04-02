/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:05:05 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/02 14:51:09 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_piece(t_piece *piece)
{
	int		i;

	i = 0;
	while (i < piece->width * piece->heigth)
	{
		ft_putchar_fd(piece->piece[i] + 48, 2);
		i++;
		if (i % piece->width == 0)
			ft_putchar_fd('\n', 2);
	}
}

void	print_grid(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->grid->width * data->grid->heigth)
	{
		ft_putchar_fd(data->grid->grid[i] + 48, 2);
		i++;
		if (i % data->grid->width == 0)
			ft_putchar_fd('\n', 2);
	}
}

void	free_data(t_data *data)
{
	free(data->grid->grid);
	free(data->grid);
	free(data->piece->piece);
	free(data->piece);
	free(data);
}

int		main(void)
{
	t_data	*data;
	char	*str;
	int		player;

	player = 0;
	while (get_next_line(0, &str) > 0)
	{
		data = process_input(str, player);
		if (data == 0)
			return (0);
		process(data);
		if (player == 0)
			player = data->player;
		free_data(data);
	}
	return (0);
}
