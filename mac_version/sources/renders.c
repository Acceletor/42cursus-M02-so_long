/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:22:59 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/20 14:57:10 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	base_render(t_vars *vars)
{
	int		i;
	int		j;
	char	**grid;

	grid = vars->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
				j * vars->base->w, i * vars->base->h);
			j++;
		}
		i++;
	}
}

void	tree_render(t_vars *vars)
{
	int		i;
	int		j;
	char	**grid;

	grid = vars->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tree->img,
					j * vars->tree->w, i * vars->tree->h);
			}
			j++;
		}
		i++;
	}
}


void	collectable_render(t_vars *vars)
{
	int		i;
	int		j;
	char	**grid;

	grid = vars->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->collect->img, j * vars->collect->w,
					i * vars->collect->h);
			}
			j++;
		}
		i++;
	}
}

void	exit_render(t_vars *vars)
{
	int		i;
	int		j;
	char	**grid;

	grid = vars->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->exit->img, j * vars->exit->w,
					i * vars->exit->h);
			}
			j++;
		}
		i++;
	}
}
