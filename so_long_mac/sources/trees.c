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

// void tree_put_image(t_vars *vars, int x, int y, int index)
// {
//     int i;
//     i = 0;
//     while (i++ < index)
//         mlx_put_image_to_window(vars->mlx, vars->win, vars->tree->img, x, y);
// }

// void set_tree(t_vars *vars, int i, int j)
// {
//     if (i == 0 && j != vars->map->width)
//         tree_put_image(vars, j * vars->base->w, i * vars->base->h, 1);

// }


void tree_put_image(t_vars *vars, int x, int y)
{
    int offset_x = (vars->base->w - vars->tree->w) / 2; // Center horizontally

    mlx_put_image_to_window(vars->mlx, vars->win, vars->tree->img, x + offset_x, y);

}

void set_tree(t_vars *vars, int i, int j)
{ // Place trees only at the top row or other conditions
    int x = j * vars->base->w + (vars->base->w - vars->tree->w) / 2;
    int y = i * vars->base->h; // Align properly in the grid

    tree_put_image(vars, x, y);

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
                // mlx_put_image_to_window(vars->mlx, vars->win,
                //                         vars->tree->img,
                //                         j * vars->base->w ,
                //                         i * vars->base->h);
                set_tree(vars, i, j);
            }
            j++;
        }
        i++;
    }
}
