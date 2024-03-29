/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 21:14:19 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/06 21:14:31 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	read_loop(char *delim_string, char **ptr, int op, char **doc)
{
	while (**ptr)
	{
		char	*tmp;
		char	*tmp2;

		tmp = *ptr;
		while (**ptr && **ptr != '\n')
			(*ptr)++;
		if (**ptr == '\n')
			(*ptr)++;
		tmp = ft_strndup(tmp, *ptr - tmp);
		if (op == DLESSDASH)
			tmp = remove_tab(tmp);
		if (!ft_strcmp(delim_string, tmp))
			break ;
		tmp2 = ft_strjoin(*doc, tmp);
		free(*doc);
		free(tmp);
		*doc = tmp2;
	}
}
