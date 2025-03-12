#include "../include/main.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
}	t_game;

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx,game->win);
	exit(0); // Terminates the program when the window is closed
}

int key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == KEY_W)
		game->y -= 10;
	else if (keycode == KEY_A)
		game->x -= 10; // Move left
	else if (keycode == KEY_S)
		game->y += 10; // Move down
	else if (keycode == KEY_D)
		game->x += 10; // Move right
	
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img, game->x,game->y);
	return (0);
}


int	main(void)
{
	t_game game;
	char	*relative_path = "./textures/Player/goblin.xpm";
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, 500, 500, "Hello world!");
	game.img = mlx_xpm_file_to_image(game.mlx, relative_path, &game.img_width, &game.img_height);
	game.x = 250;
	game.y = 250;
	
	mlx_put_image_to_window(game.mlx,game.win, game.img, game.x, game.y);
	mlx_hook(game.win, 17, 0, (void *)close_window, &game);
	mlx_key_hook(game.win,key_hook,&game);
	mlx_loop(game.mlx);
}
