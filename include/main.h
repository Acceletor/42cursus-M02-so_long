/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:16 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/13 14:19:02 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h> //exit()
# include <fcntl.h> //open()
# include <stdbool.h>

# define SPEED	15
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100
# define ESC    65307
# define WD_NAME "so_long"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_component
{
	int			wall;
	int			c;
	int			e;
	int			p;
	t_player	player;
	bool		is_valid;

}		t_component;


typedef struct s_map
{
	int		fd;
	char	*map;
	int		height;
	int		width;
	char	**grid;

}			t_map;

// map reader
void	what_map_size(int fd, t_map *map);
char	**create_map_grid(t_map *map);

// map validator
bool	component_error(char **map, t_component	*comp);
bool	check_walls(char **map, int width, int height);
void	flood_fill(char **map, int x, int y, t_component *comp);
bool	is_collectable_valid(t_component *comp, t_map *map);
bool	is_map_error(char *argv, t_map *map);

// map component
void	count_components(char **map, t_component *comp);
void	map_init(t_map *map);

// map utils
void	free_map(char **grid);
void	print_grid(char **grid);
char	**ft_strdup_2d(t_map *map);



#endif