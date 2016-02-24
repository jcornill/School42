/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:32:44 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/23 16:32:46 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
#  include <stdio.h>

typedef struct		s_link
{
	char			*room_a;
	char			*room_b;
}					t_link;

typedef struct		s_data
{
	int				nb_ants;
	t_list			*rooms_name;
	t_list			*links;
}					t_data;

t_data				*check_entry(char *str, t_list *entry);
void				err_exit(int id);
void				print_list(t_list *elem);

#endif
