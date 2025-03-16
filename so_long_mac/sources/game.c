#include "../include/main.h"




void main_display(t_vars *vars)
{
	base_render(vars);
    tree_render(vars);
}


int callbacks(t_vars *vars)
{
	// game_check()
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	if (vars->p1->move == false)
		vars->p1->active = vars->p1->idle;
	else
		vars->p1->active = vars->p1->run;
	// if (vars->exit->exit == true)
	// 	vars->exit->active = vars->exit->enabled;
	// else
	// 	vars->exit->active = vars->exit->disabled;
	mlx_put_image_to_window(vars->mlx, vars->win,vars->p1->active->img, vars->p1->x, vars->p1->y);
    if (vars->end == true)
        quit(vars);
	return (0);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}


int	game_start(t_map *map)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		free_game(vars);
		exit (1);
	}
	vars->end = false;
	vars->map = map;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		free_game(vars);
	vars->win = mlx_new_window(vars->mlx, map->width * 40, map->height * 39, WD_NAME);
	vars_nuller(vars);
	loadgame(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
