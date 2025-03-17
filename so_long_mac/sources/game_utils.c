#include "../include/main.h"

void	vars_nuller(t_vars *vars)
{
	vars->tree = NULL;
	vars->base = NULL;
	vars->collect = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
    vars->tree_pos = NULL;
}

char * pather(char *main, int i, char *end, t_vars* vars)
{
    int index1;
    int index2;
    char *path;

    path = malloc(ft_strlen(main) + ft_strlen(end) + 2);
    if (!path)
        free_game(vars);
    index1 = 0;
    index2 = 0;
    while (main[index2])
        path[index1++] = main[index2++];
    index2 = 0;
    path[index1++] = i + '0';
    while (end[index2])
        path[index1++] = end[index2++];
    path[index1] = 0;
    return (path);
}

void add_new_frame(t_vars *vars, char *path, t_animation *sprite)
{
    t_animation *temp;
    temp = malloc(sizeof(t_animation));
    if (!temp)
        free_game(vars);
    temp->img = mlx_xpm_file_to_image(vars->mlx, path, &temp->w,
                &temp->h);
    temp->next = NULL;
    while (sprite->next)
        sprite = sprite->next;
    sprite->next = temp;
}

void add_frames(t_vars *vars, char* path, t_animation *sprite)
{
    if (!sprite->img)
        sprite->img = mlx_xpm_file_to_image(vars->mlx, path, &sprite->w,
                        &sprite->h);
    else 
        add_new_frame(vars, path, sprite);
    free(path);
}
