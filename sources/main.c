/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:18:27 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/12 14:57:04 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

bool	check_error(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	char	*wholemap;
	char 	*temp;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (true);
	line = get_next_line(fd);
	if (!line)
		return (true);
	width = ft_strlen(line) -1;
	height = 1;
	wholemap = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(wholemap, line);
		free(wholemap);
		wholemap = temp;
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->map = wholemap;
	map->height = height;
	map->width = width;
	return (false);
}


int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Invalid Argument: Usage ./so_long map1.ber");
		exit(1);
	}
	if (check_error(argv[1], &map))
	{
		ft_printf("not valid");
		exit(1);
	}
	ft_printf("map:\n%s\n", map.map);
	ft_printf("width: %d \n", map.width);
	ft_printf("height: %d \n", map.height);

	return (0);
}
