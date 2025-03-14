#include "../include/main.h"


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


void load_tree(t_vars *vars)
{
    vars->tree = malloc(sizeof(t_animation));
    if (!vars->tree)
        free_game(vars);
    vars->tree->img = NULL;
    vars->tree->next = NULL;
    list_tree_img(vars, vars->tree);
}

int	loadgame(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	if (!vars->tree)
		load_tree(vars);
	// if (!vars->p1)
	// 	load_p1(vars);
    // if (!vars->exit)
    //     load_exit(vars);
	
	return (0);
}