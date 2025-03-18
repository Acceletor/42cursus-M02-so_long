/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:17:22 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/18 19:22:03 by ksuebtha         ###   ########.fr       */
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
		free(vars->tree);
		vars->tree = NULL;
		free_game(vars);
	}
	vars->tree->next = NULL;
}


int	loadgame(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	if (!vars->tree)
		load_tree(vars);
	if (!vars->p1)
		init_player(vars);
	if (!vars->p1->idle && vars->p1)
		load_p1_img(vars);


	return (0);
}
