/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:45 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/25 14:02:57 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_map(t_map *map)
{
	if (map->grid)
		free_grid(map->grid);
	if (map->map)
		free(map->map);
}

void	free_grid(char **grid)
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
	grid = NULL;
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

char	**ft_strdup_2d(t_map *map)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map->grid[i])
	{
		new_map[i] = ft_strdup(map->grid[i]);
		if (!new_map[i])
		{
			free_grid(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
