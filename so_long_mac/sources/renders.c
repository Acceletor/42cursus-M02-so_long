
#include "../include/main.h"

void base_render(t_vars *vars)
{
	int i;
	int j;
	char **grid;

	grid = vars->map->grid;
	i = 0;
	while(grid[i])
	{
		j = 0;
		while(grid[i][j])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
				 j * vars->base->w, i * vars->base->h);
			j++;
		}
		i++;
	}
}
