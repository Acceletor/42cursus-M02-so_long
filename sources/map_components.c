/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:42 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/12 18:14:23 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

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
				comp->p++;
			else if (map[i][j] != '0')
				return ;
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
}
