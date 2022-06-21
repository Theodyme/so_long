#include "so_long.h"

void    line_building(t_mlx *vars, char *line, int posy)
{
    int i;
    int posx;

    i = 0;
    posx = 0;
    while (line[i])
    {
        if (line[i] == '1')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->wall->img, posx, posy);
        else if (line[i] == '0')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img, posx, posy);
        else if (line[i] == 'E')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->exit->img, posx, posy);
        else if (line[i] == 'C')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->item->img, posx, posy);
        else if (line[i] == 'P')
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->start->img, posx, posy);
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, posx, posy);
        }
        posx += 20;
        i++;
    }
}

void    lvl_building(t_mlx *vars, t_map lvl)
{
    int i;

    i = 0;
    while(lvl.map[i])
    {
        line_building(vars, &lvl.map[i][0], (i * 20));
        i++;
    }
}
