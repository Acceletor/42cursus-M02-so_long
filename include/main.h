/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:16 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/18 16:35:45 by ksuebtha         ###   ########.fr       */
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


typedef struct s_animation
{
	void				*img;
	int					w;
	int					h;
	struct s_animation	*next;
}						t_animation;

typedef struct s_player
{
	t_animation	*idle;
	t_animation	*run;
	t_animation	*active;
	int			run_frames;
	int			idle_frames;
	int			x;
	int			y;
	int			move;
	int			move_count;
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

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*p1;
	t_animation	*collect;
	t_animation	*tree;
	t_animation	*base;
	t_animation	*exit;
	bool		end;
}	t_vars;

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

// frees
void	free_animation(t_animation *anime, t_vars *vars);
void	free_player(t_player *player, t_vars *vars);
void	free_vars(t_vars *vars);
void	free_game(t_vars *vars);

//game
void	main_display(t_vars *vars);
int		callbacks(t_vars *vars);
int		quit(t_vars *vars);
int		game_start(t_map *map);

//game_utils
void	vars_nuller(t_vars *vars);

//loader
void	load_base(t_vars *vars);
void	load_tree(t_vars *vars);
int		loadgame(t_vars *vars);

//player
void	init_player(t_vars *vars);
void	load_p1_idle(t_vars *vars, t_animation *sprite);
void	load_p1_run(t_vars *vars, t_animation *sprite);
void	load_p1_img(t_vars *vars);

//renders
void	base_render(t_vars *vars);
void	tree_render(t_vars *vars);

#endif