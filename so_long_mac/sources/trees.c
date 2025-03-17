#include "../include/main.h"


void list_tree_img(t_vars *vars, t_animation *tree)
{
    char i;
    char *path;

    path = NULL;
    i = 1;
    while (i <= 6)
    {
        path = pather("textures/tree/Tree", i, ".xpm", vars);
        add_frames(vars, path, tree);
        i++;
    }
}

void add_tree_position(t_vars *vars, int x, int y)
{
    t_tree_pos *new_pos = malloc(sizeof(t_tree_pos));
    if (!new_pos)
        free_game(vars);
    new_pos->x = x;
    new_pos->y = y;
    new_pos->next = vars->tree_pos;
    vars->tree_pos = new_pos;
}

// Center horizontally
void tree_put_image(t_vars *vars, int x, int y)
{
    int offset_x;

    offset_x = (vars->base->w - vars->tree->w) / 2; 
    mlx_put_image_to_window(vars->mlx, vars->win, vars->tree->img, x + offset_x, y);    
}
void tree_put_if_adjacent(t_vars *vars, int i, int j, int x, int y)
{
    int tree_offset_x;
    int tree_offset_y;

    tree_offset_x = (vars->base->w / 2) + ((vars->base->w - vars->tree->w) / 6);
    tree_offset_y = vars->tree->h / 2;
    if (i + 1 < vars->map->height && vars->map->grid[i + 1][j] == '1')
        tree_put_image(vars, x, y + tree_offset_y), add_tree_position(vars, x, y + tree_offset_y);
    if (j + 1 < vars->map->width && vars->map->grid[i][j + 1] == '1')
        tree_put_image(vars, x + tree_offset_x, y), add_tree_position(vars, x + tree_offset_x, y);
    if (i + 1 < vars->map->height && j + 1 < vars->map->width &&
        vars->map->grid[i + 1][j + 1] == '1' && 
        vars->map->grid[i][j + 1] == '1' && 
        vars->map->grid[i + 1][j] == '1')
        tree_put_image(vars, x + tree_offset_x, y + tree_offset_y),add_tree_position (vars, x + tree_offset_x, y + tree_offset_y);
    if (i + 1 < vars->map->height && j + 1 < vars->map->width &&
        vars->map->grid[i + 1][j + 1] == '1' &&
        vars->map->grid[i + 1][j] != '1')
        tree_put_image(vars, x + tree_offset_x, y + tree_offset_y), add_tree_position(vars, x + tree_offset_x, y + tree_offset_y);
    if (i + 1 < vars->map->height && j + 1 < vars->map->width &&
        vars->map->grid[i + 1][j - 1] == '1' &&
        vars->map->grid[i + 1][j] != '1')
        tree_put_image(vars, x - tree_offset_x, y + tree_offset_y), add_tree_position(vars, x - tree_offset_x, y + tree_offset_y);
}


void set_tree(t_vars *vars, int i, int j)
{ 
    int x;
    int y;

    x = j * vars->base->w + (vars->base->w - vars->tree->w) / 2;
    y = i * vars->base->h;
    tree_put_image(vars, x, y);
    add_tree_position(vars, x,y);
    tree_put_if_adjacent(vars, i, j, x, y);
}

void tree_render(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (i < vars->map->height)
    {
        j = 0;
        while( j < vars->map->width)
        {
            if (vars->map->grid[i][j] == '1')
            {
                set_tree(vars, i, j);
            }
            j++;
        }
        i++;
    }
}
