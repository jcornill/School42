/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:30:13 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 18:10:58 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		err(int *board, int line)
{
	int		i;

	i = -1;
	while (++i < line)
	{
		if (board[i] <= 0)
			return (0);
		if (board[i] > 10000)
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*file;
	int		nb_line;
	int		*board;

	nb_line = 0;
	if (argc != 1 && argc != 2)
		return (ft_putstrcolor("ERROR\n", "31") * 0 + 1);
	if (argc == 2)
		file = argv[1];
	if (argc == 1)
	{
		if (create_file_from_input() == -1)
			return (ft_putstrcolor("ERROR\n", "31") * 0 + 1);
		file = "file.txt";
	}
	if (argc == 2 || argc == 1)
		if ((nb_line = is_valid_file(file)) <= 0)
			return (ft_putstrcolor("ERROR\n", "31") * 0 + 1);
	board = convert_buf(file, nb_line);
	if (!err(board, nb_line))
		return (ft_putstrcolor("ERROR\n", "31") * 0 + 1);
	ft_display_board(board, nb_line);
	game(init(), board, nb_line);
	return (0);
}
