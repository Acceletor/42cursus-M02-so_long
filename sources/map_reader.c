/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:37 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/19 13:06:44 by ksuebtha         ###   ########.fr       */
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
		free(line);
		free(map->map);
		map->map = temp;
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	map->height = height;
	map->width = width;
}

char	**create_map_grid(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	if (!map->map)
		return (NULL);
	grid = ft_split(map->map, '\n');
	if (!grid)
		return (NULL);
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
			j++;
		if (j != map->width)
		{
			free_map(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

