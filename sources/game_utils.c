/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:16:32 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/18 14:45:31 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	vars_nuller(t_vars *vars)
{
	vars->tree = NULL;
	vars->base = NULL;
	vars->collect = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
	vars->end = false;
}
