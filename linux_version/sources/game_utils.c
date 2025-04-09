/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:16:32 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/04/09 09:24:59 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	vars_nuller(t_vars *vars)
{
	vars->tree = NULL;
	vars->base = NULL;
	vars->collect = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
	vars->end = false;
	vars->endgame = false;
	vars->should_quit_next_frame = false;
}

void	remove_player_map(t_vars *vars)
{
	char	**grid;
	int		i;
	int		j;

	grid = vars->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'P')
			{
				grid[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

int	count_collect(t_vars *vars)
{
	char	**grid;
	int		i;
	int		j;
	int		c;

	c = 0;
	grid = vars->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	renders(t_vars *vars)
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
				exit_render(vars, i, j);
			else if (grid[i][j] == 'C')
				collectable_render(vars, i, j);
			else if (grid[i][j] == '1')
				tree_render(vars, i, j);
			else
				base_render(vars, i, j);
			j++;
		}
		i++;
	}
	player_render(vars);
}
