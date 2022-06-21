#include "so_long.h"

int	destroy_win(t_mlx *vars)
{
	(void)vars;
	// ft_printf(1, "vars = %p, mlx = %p, win = %p, assets = %p\n", vars, vars.mlx, vars.win, vars.assets.chara.img);
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, 20, 20);
	// mlx_destroy_image(vars.mlx, vars.assets.wall.img);
	// mlx_destroy_display(vars.mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	handle_no_event(void *vars)
{
	(void)vars;
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int key_hook(int keycode, t_mlx *vars)
{
    if (keycode == XK_Escape)
        destroy_win(vars);
    return (0);
}
