/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:44 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/04/09 09:30:01 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	main_display(t_vars *vars)
{
	renders(vars);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		quit(vars);
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_S)
		update_pos(vars, keycode, vars->p1);
	return (0);
}

int	callbacks(t_vars *vars)
{
	main_display(vars);
	if (count_collect(vars) == 0 && vars->end == false)
	{
		vars->end = true;
		ft_printf("\033[36m[You can exit now]\033[0m\n");
	}
	if (vars->should_quit_next_frame == true)
	{
		vars->should_quit_next_frame = false;
		return (0);
	}
	if (vars->endgame == true)
	{
		ft_printf("Game exiting...\n");
		quit(vars);
	}
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
	remove_player_map(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 1L << 0, keypress, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	exit (0);
}
