#include "so_long.h"

int	destroy_win(t_mlx vars)
{
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}

int key_hook(int keycode, t_mlx vars)
{
    if (keycode == XK_ESCAPE)
        destroy_win(vars);
    return (0);
}