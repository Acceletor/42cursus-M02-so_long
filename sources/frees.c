/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:08:01 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/18 14:48:00 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_animation(t_animation *anime, t_vars *vars)
{
	t_animation	*next;

	if (anime)
	{
		next = anime->next;
		if (anime->img)
			mlx_destroy_image(vars->mlx, anime->img);
		free(anime);
		if (next)
			free_animation(next, vars);
	}
}

void	free_vars(t_vars *vars)
{
	free_animation(vars->base, vars);
	free_animation(vars->tree, vars);
}


void	free_game(t_vars *vars)
{
	ft_printf("NOT ENOUGH MEMORY TO MALLOC || no image");
	if (vars)
	{
		if (vars->map)
		{
			free_map(vars->map->grid);
			free(vars->map);
		}
		free_vars(vars);
	}
}