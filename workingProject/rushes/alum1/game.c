/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:49:15 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 18:22:59 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int		*init_computer(int *board, int nb_line)
{
	int		i;
	int		*p;

	p = ft_memalloc(sizeof(int) * (nb_line + 2));
	p[0] = 1;
	if (board[0] % 4 == 1)
		p[1] = -1;
	else
		p[1] = 1;
	i = 0;
	while (++i < nb_line)
	{
		if (board[i] % 4 == 1)
			p[i + 1] = -1;
		else
			p[i + 1] = 1;
		if (p[i] == -1)
			p[i + 1] *= -1;
	}
	return (p);
}

static int		play_player(int *board, int nb_line)
{
	char	b[256];

	while (1)
	{
		ft_putstr("Combien retirer d'allum ? (1, 2, 3 ou q pour quit) ");
		if (read(0, b, 256) > 2 || b[1] != '\n')
			ft_putstrcolor("Valeur invalide !\n", "1;31");
		else if (b[0] != 'q' && b[0] != '1' && b[0] != '2' && b[0] != '3')
			ft_putstrcolor("Valeur invalide !\n", "1;31");
		else if ((b[0] - '0') > board[nb_line - 1] && b[0] != 'q')
			ft_putstrcolor("Valeur invalide !\n", "1;31");
		else if (b[0] == 'q')
			return (0);
		else
			break ;
	}
	return (b[0] - '0');
}

static void		victoire(int player)
{
	if (player == 1)
	{
		ft_putstrcolor("Vous avez gagner !\n", "32");
	}
	else
		ft_putstrcolor("L'ordinateur a gagner !\n", "31");
}

static void		display(int *board, int nb_line)
{
	int		i;

	i = -1;
	while (++i < longgest_line(board))
		write(1, "=", 1);
	write(1, "\n", 1);
	ft_display_board(board, nb_line);
}

void			game(int player, int *board, int nb_line)
{
	int		ret;
	int		*init;

	ret = 1;
	init = init_computer(board, nb_line);
	while (board[0] > 0)
	{
		display(board, nb_line);
		if (player == 1)
		{
			ret = play_player(board, nb_line);
			if (ret == 0)
				return ;
			player++;
		}
		else
		{
			ret = computer(board, nb_line, ret, init);
			player--;
		}
		if ((board[nb_line - 1] -= ret) <= 0)
			nb_line--;
	}
	victoire(player);
}
