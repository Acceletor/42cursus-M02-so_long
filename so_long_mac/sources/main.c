/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:18:27 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/13 19:53:13 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

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
		ft_printf("Error: not valid\n");
		free_map(map.grid);
		free(map.map);
		exit(1);
	}
	print_grid(map.grid);
	game_start(&map);
	ft_printf("Pass\n");
	free_map(map.grid);
	free(map.map);
	return (0);
}

