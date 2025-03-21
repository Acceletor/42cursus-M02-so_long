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

static void move_player(t_vars *vars, t_player *p1 , int new_i, int new_j)
{
	p1->x = new_j * vars->base->w;
	p1->y = new_i * vars->base->h;
	if (vars->map->grid[new_i][new_j] == 'C')
	{
		vars->map->grid[new_i][new_j] = '0';
		ft_printf("\033[33m[You have collected coin]\033[0m\n");
	}
	vars->p1->move = 1;
	vars->p1->move_count++;
	ft_printf("Current Move: %d\n", vars->p1->move_count);
	if (vars->map->grid[new_i][new_j] == 'E' && vars->end == true)
	{
		ft_printf("\033[35m[You Won!!]\033[0m\n");
		vars->endgame = true;
		vars->should_quit_next_frame = true;
	}
}


void	update_pos(t_vars *vars, int keycode, t_player *p1)
{
	int	new_j;
	int	new_i;
	int i;
	int j;

	i = p1->y / vars->base->h;
	j = p1->x / vars->base->w;
	new_i = p1->y / vars->base->h;
	new_j = p1->x / vars->base->w;
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
		move_player(vars, p1, new_i, new_j);
}


