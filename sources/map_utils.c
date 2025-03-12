/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:45 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/12 18:20:44 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	free_map(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	print_grid(char **grid)
{
	int	i;

	if (!grid)
	{
		ft_printf("Error: Null grid\n");
		return ;
	}
	i = 0;
	while (grid[i])
	{
		ft_printf("%s\n", grid[i]);
		i++;
	}
}
