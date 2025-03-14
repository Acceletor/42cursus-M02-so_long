#include "../include/main.h"

// void load_p1(t_vars *vars)
// {
//     int i;
//     int j;

//     vars->p1 = malloc(sizeof(t_p));
//     if (!vars->p1)
//         free_game(vars);
//     vars->p1->move_count = 0;
//     i = 0;
//     while(vars->map->grid[i])
//     {
//         j = 0;
//         while(vars->map->grid[i][j])
//         {
//             if (vars->map->grid[i][j] == 'P')
//             {
//                 vars->p1->x = j * vars->tree->w;
//                 vars->p1->y = i * vars->tree->h;
//             }
//             j++;
//         }
//         i++;
//     }
//     vars->p1->idle = NULL;
//     vars->p1->run = NULL;
// }