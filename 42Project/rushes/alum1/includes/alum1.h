/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:54:10 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 18:15:41 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		is_valid_file(char *file);
int		ft_putstrcolor(char *str, char *color_code);
int		create_file_from_input(void);
int		init(void);
void	ft_display_board(int *nb, int l);
int		*convert_buf(char *file, int const nb_line);
void	game(int player, int *board, int nb_line);
int		longgest_line(int *nb);
int		computer(int *board, int nb_line, int player, int *init);

#endif
