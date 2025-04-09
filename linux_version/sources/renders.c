/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:22:59 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/04/09 09:30:43 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	base_render(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
		j * vars->base->w, i * vars->base->h);
}

void	tree_render(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tree->img,
		j * vars->tree->w, i * vars->tree->h);
}

void	player_render(t_vars *vars)
{
	if (vars->p1->e == false)
		vars->p1->active = vars->p1->idle;
	else
		vars->p1->active = vars->p1->at_exit;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->p1->active->img, vars->p1->x, vars->p1->y);
}

void	collectable_render(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->collect->img, j * vars->collect->w,
		i * vars->collect->h);
}

void	exit_render(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit->img, j * vars->exit->w,
		i * vars->exit->h);
}
