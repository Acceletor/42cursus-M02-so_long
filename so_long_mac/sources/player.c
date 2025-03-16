#include "../include/main.h"

void load_p1(t_vars *vars)
{
    int i;
    int j;

    vars->p1 = malloc(sizeof(t_p));
    if (!vars->p1)
        free_game(vars);
    vars->p1->move_count = 0;
    i = 0;
    while(vars->map->grid[i])
    {
        j = 0;
        while(vars->map->grid[i][j])
        {
            if (vars->map->grid[i][j] == 'P')
            {
                vars->p1->x = j * vars->tree->w;
                vars->p1->y = i * vars->tree->h;
            }
            j++;
        }
        i++;
    }
    vars->p1->idle = NULL;
    vars->p1->run = NULL;
    vars->p1->active = NULL;
    vars->p1->move = false;
}

void	load_p1_idle(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
    i = 1;
	while (i <= 7)
	{
		path = pather("./textures/Player/idle/goblin_idle_", i, ".xpm", vars);
		add_frames(vars, path, sprite);
		i++;
	}
}

void	load_p1_run(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
    i = 1;
	while (i <= 7)
	{
		path = pather("./textures/Player/idle/goblin_idle_", i, ".xpm", vars);
		add_frames(vars, path, sprite);
		i++;
	}
}

void load_p1_anims(t_vars *vars)
{
    vars->p1->idle  = malloc(sizeof(t_animation));
    if (!vars->p1->idle)
        free_game(vars);
    vars->p1->idle->img = NULL;
    vars->p1->idle->next = NULL;
    load_p1_idle(vars,vars->p1->idle);
    vars->p1->run  = malloc(sizeof(t_animation));
    if (!vars->p1->run)
        free_game(vars);
    vars->p1->run->img = NULL;
    vars->p1->run->next = NULL;
    load_p1_idle(vars,vars->p1->run);
}