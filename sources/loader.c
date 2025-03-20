/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:17:22 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/20 14:13:15 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	load_base(t_vars *vars)
{
	vars->base = malloc(sizeof(t_animation));
	if (!vars->base)
		free_game(vars);
	vars->base->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/empty_space/ground.xpm",
			&vars->base->w, &vars->base->h);
	if (!vars->base->img)
	{
		ft_printf("Error: Failed to load ground texture\n");
		free(vars->base);
		vars->base = NULL;
		free_game(vars);
	}
	vars->base->next = NULL;
}

void	load_tree(t_vars *vars)
{
	vars->tree = malloc(sizeof(t_animation));
	if (!vars->tree)
		free_game(vars);
	vars->tree->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/tree/tree.xpm",
			&vars->tree->w, &vars->tree->h);
	if (!vars->tree->img)
	{
		ft_printf("Error: Failed to load tree texture\n");
		free(vars->tree);
		vars->tree = NULL;
		free_game(vars);
	}
	vars->tree->next = NULL;
}

void	load_collect(t_vars *vars)
{
	vars->collect = malloc(sizeof(t_animation));
	if (!vars->collect)
		free_game(vars);
	vars->collect->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/collectable.xpm",
			&vars->collect->w, &vars->collect->h);
	if (!vars->collect->img)
	{
		ft_printf("Error: Failed to load collectable texture\n");
		free(vars->collect);
		vars->collect = NULL;
		free_game(vars);
	}
	vars->collect->next = NULL;
}

void	load_exit(t_vars *vars)
{
	vars->exit = malloc(sizeof(t_animation));
	if (!vars->exit)
		free_game(vars);
	vars->exit->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/goldmine_active.xpm",
			&vars->exit->w, &vars->exit->h);
	if (!vars->exit->img)
	{
		ft_printf("Error: Failed to load exit texture\n");
		free(vars->exit);
		vars->exit = NULL;
		free_game(vars);
	}
	vars->exit->next = NULL;
}

int	loadgame(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	if (!vars->tree)
		load_tree(vars);
	if (!vars->p1)
		init_player(vars);
	if (!vars->p1->idle && !vars->p1->run)
		load_p1_img(vars);
	if (!vars->collect)
		load_collect(vars);
	if (!vars->exit)
		load_exit(vars);
	return (0);
}
