/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:40 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/12 18:20:53 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

bool	component_error(char **map)
{
	t_component	comp;

	comp.wall = 0;
	comp.c = 0;
	comp.e = 0;
	comp.p = 0;

	count_components(map, &comp);

	if (comp.e != 1 || comp.p != 1 || comp.c < 1)
		return (true);
	return (false);
}

bool	check_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (true);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (true);
		i++;
	}
	return (false);
}


bool	is_map_error(char *argv, t_map *map)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (true);
	what_map_size(fd, map);
	if (map->width == map->height
		|| map->width == 0 || map->height == 0)
		return (true);
	map->grid = create_map_grid(map);
	if (!map->grid)
		return (true);
	if (component_error(map->grid))
		return (true);
	if (check_walls(map->grid, map->width, map->height))
		return (true);
	return (false);
}
