/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:06:55 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/19 13:46:09 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	init_player(t_vars *vars)
{
	int	i;
	int	j;

	vars->p1 = malloc(sizeof(t_player));
	if (!vars->p1)
		free_game(vars);
	vars->p1->move = false;
	vars->p1->move_count = 0;
	i = 0;
	while (i < vars->map->height)
	{
		j = 0;
		while (j < vars->map->width)
		{
			if (vars->map->grid[i][j] == 'P')
			{
				vars->p1->x = j * vars->base->w;
				vars->p1->y = i * vars->base->h;
			}
			j++;
		}
		i++;
	}
	vars->p1->idle = NULL;
	vars->p1->run = NULL;
}

void	load_p1_idle(t_vars *vars, t_animation *sprite)
{
	sprite->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/player/player_idle.xpm",
			&sprite->w, &sprite->h);
	if (!sprite->img)
	{
		ft_printf("Error: Failed to load player idle texture\n");
		free(vars->p1->idle);
		vars->p1->idle = NULL;
		return ;
	}
	sprite->next = NULL;
}

void	load_p1_run(t_vars *vars, t_animation *sprite)
{
	sprite->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/player/player_idle.xpm",
			&sprite->w, &sprite->h);
	if (!sprite->img)
	{
		ft_printf("Error: Failed to load player run texture\n");
		free(vars->p1->run);
		vars->p1->run = NULL;
		return ;
	}
	sprite->next = NULL;
}

void	load_p1_img(t_vars *vars)
{
	vars->p1->idle = malloc(sizeof(t_animation));
	if (!vars->p1->idle)
		free_game(vars);
	vars->p1->idle->img = NULL;
	vars->p1->idle->next = NULL;
	load_p1_idle(vars, vars->p1->idle);
	vars->p1->run = malloc(sizeof(t_animation));
	if (!vars->p1->run)
		free_game(vars);
	vars->p1->run->img = NULL;
	vars->p1->run->next = NULL;
	load_p1_run(vars, vars->p1->run);
}
