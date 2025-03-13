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

void free_vars(t_vars vars)


void free_game(t_vars *vars)
{
	ft_printf("NOT ENOUGH MEMORY TO MALLOC");
	if (var)
}

int load_base(t_vars *vars)
{
	vars->base = malloc(sizeof(t_animation));
	if(!vars->base)
		free_game();

}




int	loadplayer(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	if (!vars->wall)
		load_wall(vars);
	if (!vars->p1)
		load_p1(vars, map);
	
		
}


void	vars_nuller(t_vars *vars)
{
	vars->wall = NULL;
	vars->base = NULL;
	vars->collect = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
}

int	game_start(t_map *map)
{
	t_vars	*vars;

	vars = NULL;
	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		free_map(map->grid);
		free(map->map);
	}
	vars->end = false;
	vars->map = map;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map->width, map->height, WD_NAME);
	vars_nuller(vars);
	loadplayer(vars, map);

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
		ft_printf("Error: not valid\n");
		free_map(map.grid);
		free(map.map);
		exit(1);
	}
	game_start(&map);
	ft_printf("Pass\n");
	free_map(map.grid);
	free(map.map);
	return (0);
}
