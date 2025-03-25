/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:42 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/13 14:18:42 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	player_position(t_component *comp, int x, int y)
{
	comp->player.x = x;
	comp->player.y = y;
	comp->p += 1;
}

void	count_components(char **map, t_component *comp)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				comp->wall++;
			else if (map[i][j] == 'C')
				comp->c++;
			else if (map[i][j] == 'E')
				comp->e++;
			else if (map[i][j] == 'P')
				player_position(comp, j, i);
			else if (map[i][j] != '0')
				comp->is_valid = false;
			j++;
		}
		i++;
	}
}

void	map_init(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->grid = NULL;
}
