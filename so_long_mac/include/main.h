#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-opengl/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h> //exit()
# include <fcntl.h> //open()

# define SPEED	15
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define ESC 53
# define WD_NAME "so_long"

typedef struct s_player
{
    int x;
    int y;
} t_player;

typedef struct s_map_errs
{
    int w;
    int c;
    int e;
    int p;
} t_map_error;


#endif