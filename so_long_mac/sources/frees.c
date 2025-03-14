#include "../include/main.h"


void free_animation(t_animation *anime, t_vars *vars)
{
	if (anime)
	{
		free_animation(anime->next, vars);
		if (anime->img)
			mlx_destroy_image(vars->mlx, anime->img);
		free(anime);
	}
}

void free_vars(t_vars *vars)
{
	if (vars)
	{
		free_animation(vars->base, vars);
        free_animation(vars->tree, vars);
		free(vars);
	}
}


void free_game(t_vars *vars)
{
	ft_printf("FAIL to MALLOC or NO IMAGE\n");
	if (vars)
	{
		if (vars->map)
		{
			free_map(vars->map->grid);
			free(vars->map);
		}
        free_vars(vars);
	}
	exit(0);
}
