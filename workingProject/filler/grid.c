#include "filler.h"

t_grid	*create_grid(int x, int y)
{
	t_grid	*grid;

	if (!(grid = ft_memalloc(sizeof(t_grid))))
		return (NULL);
	if (!(grid->grid = ft_memalloc(x * y + 1)))
		return (NULL);
	grid->x = x;
	grid->y = y;
	return (grid);
}

void	print_grid(char *grid)
{
	int		i;
	int		j;

	i = -1;
    while (++i < grid->y)
	{
		j = -1;
		while (++j < grid->x)
		{
			if (grid->grid[grid->x + ])
		}
	}
}
