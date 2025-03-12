/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:16:16 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/12 14:26:05 by ksuebtha         ###   ########.fr       */
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
    int x;
    int y;
} t_player;

typedef struct s_map
{
	int		fd;
	char	*map;
	int		height;
	int		width;

}			t_map;


#endif