/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:01:28 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 18:11:08 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		computer(int *board, int nb_line, int player, int *init)
{
	int		i;
	int		ret;

	player = 0;
	i = -1;
	ret = 4 - (board[nb_line - 1] % 4 + 1);
	if (init[nb_line - 1] == -1)
		ret = (board[nb_line - 1] % 4);
	if (board[nb_line - 1] <= 4 && nb_line - 1 == 0)
		ret = board[0] - 1;
	if (ret == 4)
		ret = 1;
	if (ret == 0)
		ret = 2;
	return (ret);
}
