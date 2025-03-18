/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:08:01 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/18 17:14:58 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_animation(t_animation *anime, t_vars *vars)
{
	t_animation	*next;

	while (anime)
	{
		next = anime->next;
		if (anime->img && vars->mlx)
			mlx_destroy_image(vars->mlx, anime->img);
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
	free(vars);
}


void	free_game(t_vars *vars)
{
	ft_printf("NOT ENOUGH MEMORY TO MALLOC || Fail to load texture\n");
	if (!vars)
		exit(1);
	if (vars->map)
	{
		if (vars->map->grid)
			free_map(vars->map->grid);
		free(vars->map);
		vars->map = NULL;
	}
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);

	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);                
	}
	free_vars(vars);
	exit(1);
}
