/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:12 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/10 12:46:48 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h> // Needed for exit()

int	close_window(void *param)
{
	(void)param;
	exit(0); // Terminates the program when the window is closed
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
}
