/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:08:01 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/20 14:15:10 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_animation(t_animation *anime, t_vars *vars)
{
	t_animation	*next;

	while (anime)
	{
		next = anime->next;
		if (anime->img)
		{
			mlx_destroy_image(vars->mlx, anime->img);
			anime->img = NULL;
		}
		free(anime);
		anime = next;
	}
}

void	free_player(t_player *player, t_vars *vars)
{
	if (!player)
		return ;
	if (player->idle)
		free_animation(player->idle, vars);
	if (player->run)
		free_animation(player->run, vars);
	free(player);
}

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->base)
		free_animation(vars->base, vars);
	if (vars->tree)
		free_animation(vars->tree, vars);
	if (vars->p1)
		free_player(vars->p1, vars);
	if (vars->collect)
		free_animation(vars->collect, vars);
	if (vars->exit)
		free_animation(vars->exit, vars);
}


void	free_game(t_vars *vars)
{
	ft_printf("Closing game and freeing resources...\n");
	if (!vars)
		exit(1);
	if (vars->map)
		free_map(vars->map);
	if (vars)
		free_vars(vars);
	if (vars->win && vars->mlx)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	// if (vars->mlx)
	// {
	// 	mlx_destroy_window(vars->mlx);
	// 	free(vars->mlx);
	// 	vars->mlx = NULL;
	// }
	free(vars);
	exit (0);
}

