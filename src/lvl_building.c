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
		{
			vars->items += 1;
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->item->img, posx, posy);
		}
		else if (line[i] == 'P')
        {
			vars->ppos_x = i;
			vars->ppos_y = posy / SIZE;
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->start->img, posx, posy);
            mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, posx, posy);
        }
        posx += SIZE;
        i++;
    }
}

void    lvl_building(t_mlx *vars)
{
    int i;

    i = 0;
	vars->items = 0;
    while(vars->lvl->map[i])
    {
        line_building(vars, &vars->lvl->map[i][0], (i * SIZE));
        i++;
    }
}
