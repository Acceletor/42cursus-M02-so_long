/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:18:27 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/04/08 15:47:25 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static bool	check_mapfile(char *filename)
{
	int	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Invalid Argument: Usage ./so_long map1.ber");
		exit(1);
	}
	if (!check_mapfile(argv[1]))
	{
		ft_printf("Invalid map: Please use .ber file for the map");
		exit(1);
	}
	map_init(&map);
	if (is_map_error(argv[1], &map))
	{
		ft_printf("Error: not valid\n");
		free_map(&map);
		exit(1);
	}
	game_start(&map);
	free_grid(map.grid);
	free(map.map);
	return (0);
}
