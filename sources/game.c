/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:44 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/18 18:39:24 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"


void	main_display(t_vars *vars)
{
	base_render(vars);
	tree_render(vars);
}

int	callbacks(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);

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
		exit (1);
	}
	vars->end = false;
	vars->map = map;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		free_game(vars);
	vars->win = mlx_new_window(vars->mlx, map->width * 40,
			map->height * 39, WD_NAME);
	vars_nuller(vars);
	loadgame(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
