#include "../minilibx-opengl/mlx.h"

#include <stdlib.h> // Needed for exit()

int	close_window(void *param)
{
	(void)param;
	exit(0); // Terminates the program when the window is closed
}

int	main(void)
{
	void	*mlx; // connection
	void	*mlx_win; // window

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	mlx_loop(mlx); //initiate the window rendering. 
}

