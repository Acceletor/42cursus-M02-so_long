#include "../include/main.h"

bool over_boundary(int x, int y, t_vars *vars)
{

    t_tree_pos *current = vars->tree_pos;
    while (current)
    {
        if (x >= current->x && x < current->x + vars->tree->w &&
            y >= current->y && y < current->y + vars->tree->h)
            return false; // Tree detected → Block movement
        current = current->next;
    }

    return false; // Safe to move
}

bool position_checker(int x, int y, t_vars *vars)
{
    return !over_boundary(x, y, vars); // Returns false if movement is blocked
}


void update_p_pos(int keycode, t_p *p1, t_vars *vars)
{
    if (keycode == KEY_W)
    {
        if (position_checker(p1->x, p1->y - SPEED, vars))
            p1->y -= SPEED;
    }    
    if (keycode == KEY_S)
    {
        if (position_checker(p1->x, p1->y + SPEED, vars))
            p1->y += SPEED;
    }
    if (keycode == KEY_A)
    {
        if (position_checker(p1->x - SPEED, p1->y, vars))
            p1->x -= SPEED;
    }    
    if (keycode == KEY_D)
    { 
        if (position_checker(p1->x + SPEED, p1->y, vars))
            p1->x += SPEED;
    }    
    p1->move = 1;
}