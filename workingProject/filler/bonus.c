/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 11:23:42 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/02 14:13:55 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_screen(void)
{
	char	*clr;

	clr = ft_strdup("\033[1;1H\033[2J");
	write(1, clr, 12);
	free(clr);
}

void	gotoxy(int x, int y)
{
	ft_putchar(0x1B);
	ft_putchar('[');
	ft_putnbr(y);
	ft_putchar(';');
	ft_putnbr(x);
	ft_putchar('H');
}

void	cursor(char *str)
{
	if (ft_strchr(str, 'P') != 0)
	{
		gotoxy(0, 10);
	}
	if (ft_strchr(str, '=') != 0)
		gotoxy(0, 90);
}

void	annexe(char *str, int i)
{
	if (str[i] == 'x' && (str[i - 1] == 'X' || str[i - 1] == '.' ||
	str[i - 1] == 'x' || str[i - 1] == ' '))
		ft_putstr("\033[1;31m");
	else if (str[i] == 'X')
		ft_putstr("\033[31m");
	else if (str[i] == 'o' && (str[i - 1] == 'O' || str[i - 1] == '.' ||
	str[i - 1] == 'o' || str[i - 1] == ' '))
		ft_putstr("\033[1;34m");
	else if (str[i] == 'O')
		ft_putstr("\033[34m");
}

int		main(int ac, char **av)
{
	char	*str;
	int		i;

	clear_screen();
	while (get_next_line(0, &str) > 0)
	{
		i = -1;
		if (ac == 2 && ft_strcmp(av[1], "-s") == 0)
			cursor(str);
		while (str[++i])
		{
			annexe(str, i);
			ft_putchar(str[i]);
			ft_putstr("\033[0m");
		}
		ft_putchar('\n');
	}
	return (0);
}
