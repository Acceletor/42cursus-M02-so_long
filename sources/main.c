/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:18:27 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/12 17:59:31 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	what_map_size(int fd, t_map *map)
{
	char	*line;
	int		height;
	int		width;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		return ;
	width = ft_strlen(line)-1;
	height = 1;
	map->map = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(map->map, line);
		free(map->map);
		map->map = temp;
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->height = height;
	map->width = width;
}

char	**create_map_grid(t_map *map)
{
	if (!map->map)
	{
		return (NULL);
	}
	return (ft_split(map->map, '\n'));
}

bool	component_error(char **map)
{
	t_component	comp;
	int			i;
	int			j;

	comp.wall = 0;
	comp.c = 0;
	comp.e = 0;
	comp.p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				comp.wall++;
			else if (map[i][j] == 'C')
				comp.c++;
			else if (map[i][j] == 'E')
				comp.e++;
			else if (map[i][j] == 'P')
				comp.p++;
			else if (map[i][j] != '0')
				return (true);
			j++;
		}
		i++;
	}
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

void	map_init(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
}

void	free_map(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	print_grid(char **grid)
{
	int	i;

	if (!grid)
	{
		ft_printf("Error: Null grid\n");
		return ;
	}
	i = 0;
	while (grid[i])
	{
		ft_printf("%s\n", grid[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Invalid Argument: Usage ./so_long map1.ber");
		exit(1);
	}
	map_init(&map);
	if (is_map_error(argv[1], &map))
	{
		ft_printf("Error: not valid");
		exit(1);
	}
	ft_printf("map:\n");
	print_grid(map.grid);
	free_map(map.grid);
	free(map.map);
	return (0);
}
