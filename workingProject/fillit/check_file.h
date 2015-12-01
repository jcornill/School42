/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:21:40 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/01 21:29:50 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_FILE_H
# define CHECK_FILE_H
# include <unistd.h>
# include <fcntl.h>
# define OPEN(FILE, VAR) VAR = open(FILE, O_RDONLY); if (VAR == -1) return (0);
# define BUFF_SIZE 21

int	is_valid_file(char *file);

#endif
