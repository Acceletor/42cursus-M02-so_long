/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:48:54 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/20 17:41:08 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	move_player(t_vars *vars, int keycode, int i, int j)
{
	int	new_j;
	int	new_i;

	new_i = i;
	new_j = j;
	if (keycode == KEY_W && i - 1 >= 0 && vars->map->grid[i - 1][j] != '1')
		new_i--;
	else if (keycode == KEY_S && vars->map->grid[i + 1][j]
		&& vars->map->grid[i + 1][j] != '1')
		new_i++;
	else if (keycode == KEY_A && j - 1 >= 0 && vars->map->grid[i][j - 1] != '1')
		new_j--;
	else if (keycode == KEY_D && vars->map->grid[i][j + 1]
		&& vars->map->grid[i][j + 1] != '1')
		new_j++;
	if (new_i != i || new_j != j)
	{
		vars->map->grid[i][j] = '0';
		vars->map->grid[new_i][new_j] = 'P';
		vars->p1->move = 1;
		vars->p1->move_count++;
		ft_printf("Current Move: %d\n", vars->p1->move_count);
	}
}

void	update_pos(t_vars *vars, int keycode)
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
                move_player(vars, keycode, i, j);
                return;
			}
			j++;
		}
		i++;
	}
}
