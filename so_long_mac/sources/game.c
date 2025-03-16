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

void update_p_pos(int keycode, t_p *p1)
{
	if (keycode == KEY_W)
			p1->y -= SPEED;
	if (keycode == KEY_S)
			p1->y += SPEED;
	if (keycode == KEY_A)
			p1->x -= SPEED;
	if (keycode == KEY_D)
			p1->x += SPEED;
	p1->move = 1;
}


int keypress(int keycode,t_vars *vars)
{
	if (keycode == ESC)
		quit(vars);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_D || keycode == KEY_S)
		update_p_pos(keycode, vars->p1);
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
	mlx_hook(vars->win, 2, 0, keypress, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
