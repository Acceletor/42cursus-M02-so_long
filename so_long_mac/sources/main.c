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

void free_animation(t_animation *anime, t_vars *vars)
{
	if (anime)
	{
		free_animation(anime->next, vars);
		if (anime->img)
			mlx_destroy_image(vars->mlx, anime->img);
		free(anime);
	}
}

void free_vars(t_vars *vars)
{
	if (vars)
	{
		free_animation(vars->base, vars);
		free(vars);
	}
}


void free_game(t_vars *vars)
{
	ft_printf("ERROR in MALLOC or NO IMAGE\n");
	if (vars)
	{
		if (vars->map)
		{
			free_map(vars->map->grid);
			free(vars->map);
		}
		free(vars);
	}
	exit(0);
}

void load_base(t_vars *vars)
{
	vars->base = malloc(sizeof(t_animation));
	if(!vars->base)
		free_game(vars);
	vars->base->img = mlx_xpm_file_to_image(vars->mlx,
					"./textures/empty_space/ground.xpm",
					&vars->base->w, &vars->base->h);
	if (!vars->base->img)
	{
		free(vars->base);
		vars->base = NULL;
		free_game(vars);
	}
	vars->base->next = NULL;
}




int	loadplayer(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	// if (!vars->wall)
	// 	load_wall(vars);
	// if (!vars->p1)
	// 	load_p1(vars);
	
	return (0);
}


void	vars_nuller(t_vars *vars)
{
	vars->wall = NULL;
	vars->base = NULL;
	vars->collect = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
}

void base_render(t_vars *vars)
{
	int i;
	int j;
	char **grid;

	grid = vars->map->grid;
	i = 0;
	while(grid[i])
	{
		j = 0;
		while(grid[i][j])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
				 j * vars->base->w, i * vars->base->h);
			j++;
		}
		i++;
	}
}


void main_display(t_vars *vars)
{
	base_render(vars);
}


int callbacks(t_vars *vars)
{
	// game_check()
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);

	return (0);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}

int	game_start(t_map *map)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		free_game(vars);
		exit (1);
	}
	vars->end = false;
	vars->map = map;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		free_game(vars);

	vars->win = mlx_new_window(vars->mlx, map->width * 39, map->height * 40, WD_NAME);
	vars_nuller(vars);
	loadplayer(vars);
	main_display(vars);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
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

