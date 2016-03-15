/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:21:45 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/14 16:50:34 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

int		*get_pile_a(char **str, int nb_num, int opt);
int		*get_pile_b(int nb_num);
void	swap(int *pile, int num, char c, int opt);
void	swaps(int *pile_a, int *pile_b, int num);
void	push(int *pile1, int *pile2, int num, char c);
void	rotate(int *pile, int num, char c, int opt);
void	rotates(int *pile_a, int *pile_b, int num);
void	rrotate(int *pile, int num, char c, int opt);
void	rrotates(int *pile_a, int *pile_b, int num, int opt);
void	process(int *pile_a, int *pile_b, int num, int opt);
int		where_min(int *pile, int num);

void	debug_print(int *pile_a, int *pile_b, int num);
void	move_left_pile(int *pile, int num);
void	move_right_pile(int *pile, int num);

#endif
