/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:44 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:34 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	main_display(t_vars *vars)
{
	base_render(vars);
	tree_render(vars);
	player_render(vars);
	collectable_render(vars);
	exit_render(vars);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		quit(vars);
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_S)
	{
		update_pos(vars, keycode);
		mlx_clear_window(vars->mlx, vars->win);
		main_display(vars);
	}

	return (0);
}

int	callbacks(t_vars *vars)
{
	// game_check()
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	if (vars->end == true)
		quit(vars);
	return (0);
}

int	quit(t_vars *vars)
{
	free_game(vars);
	exit(0);
}

int	game_start(t_map *map)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		exit (1);
	}
	vars->end = false;
	vars->map = map;
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		free(vars);
		exit (1);
	}
	vars->win = mlx_new_window(vars->mlx, map->width * 40,
			map->height * 39, WD_NAME);
	vars_nuller(vars);
	loadgame(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 1L << 0, keypress, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	exit (0);
}
