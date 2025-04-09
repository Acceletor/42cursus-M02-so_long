/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:40 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/04/09 09:27:15 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

bool	component_error(char **map, t_component	*comp)
{
	comp->wall = 0;
	comp->c = 0;
	comp->e = 0;
	comp->p = 0;
	comp->player.x = 0;
	comp->player.y = 0;
	comp->is_valid = true;
	count_components(map, comp);
	if (comp->e != 1 || comp->p != 1 || comp->c < 1
		|| !comp->is_valid)
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

void	flood_fill(char **map, int x, int y, t_component *comp)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		comp->c--;
	if (map[y][x] == 'E')
		comp->e--;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, comp);
	flood_fill(map, x - 1, y, comp);
	flood_fill(map, x, y + 1, comp);
	flood_fill(map, x, y - 1, comp);
}

bool	is_collectable_valid(t_component *comp, t_map *map)
{
	char	**temp_map;

	temp_map = ft_strdup_2d(map);
	if (!temp_map)
		return (false);
	flood_fill(temp_map, comp->player.x, comp->player.y, comp);
	free_grid(temp_map);
	return (comp->c == 0 && comp->e == 0);
}

bool	is_map_error(char *argv, t_map *map)
{
	int			fd;
	t_component	comp;

	ft_bzero(&comp, sizeof(t_component));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (true);
	what_map_size(fd, map);
	if (map->width == 0 || map->height == 0)
		return (true);
	map->grid = create_map_grid(map);
	if (!map->grid)
		return (true);
	if (component_error(map->grid, &comp))
		return (true);
	if (check_walls(map->grid, map->width, map->height))
		return (true);
	if (!is_collectable_valid(&comp, map))
		return (true);
	return (false);
}
