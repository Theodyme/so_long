#include "so_long.h"

int	destroy_win(t_mlx *vars)
{
	(void)vars;
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, 20, 20);
	// mlx_destroy_image(vars->mlx, vars->assets->chara->img);
	// mlx_destroy_display(vars->mlx);
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img, (17 * vars->lvl->x), (20 * (vars->lvl->y)));
	mlx_string_put(vars->mlx, vars->win, (17 * vars->lvl->x), (20 * (vars->lvl->y) + 10), 0xFFFFFFFF, ft_itoa(vars->mv));
    if (keycode == XK_Escape)
        destroy_win(vars);
	else if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
	{
		move_up(vars);
	}
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		move_down(vars);
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		move_left(vars);
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		move_right(vars);
    return (0);
}
