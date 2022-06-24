#include "so_long.h"

int	destroy_win(t_mlx *vars)
{
	(void)vars;
	// mlx_destroy_window(vars->mlx, vars->win);
	// mlx_destroy_display(vars->mlx);
	exit(free_global(vars, 1));
	return (0);
}

int	handle_no_event(void *vars)
{
	(void)vars;
	return (0);
}

int key_hook(int keycode, t_mlx *vars)
{
	// char *count;

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
	// count = ft_itoa(vars->mv);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img, (17 * vars->lvl->x), (SIZE * (vars->lvl->y)));
	mlx_string_put(vars->mlx, vars->win, (17 * vars->lvl->x), (SIZE * (vars->lvl->y) + 10), 0xFFFFFFFF, ft_itoa(vars->mv));
	// free(count);
    return (0);
}
