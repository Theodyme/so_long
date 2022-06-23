#include "so_long.h"

// void	success_exit(t_mlx vars)
// {
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->exit->img, (vars->ppos_x * 20), (vars->ppos_y * 20));
// }

// void	pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

t_data	*data_init(t_mlx *vars, char *path)
{
	int size;
	t_data *data;

	size = 20;
	data = malloc(sizeof(t_data));
	data->img = mlx_new_image(vars->mlx, 20, 20);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->end);
	data->img = mlx_xpm_file_to_image(vars->mlx, path, &size, &size);
	return (data);
}

void	assets_init(t_mlx *vars, t_assets *assets)
{
	assets->chara = data_init(vars, "./character.xpm");
	assets->wall = data_init(vars, "./wall.xpm");
	assets->bg = data_init(vars, "./bg.xpm");
	assets->exit = data_init(vars, "./exit.xpm");
	assets->item = data_init(vars, "./item.xpm");
	assets->start = data_init(vars, "./start.xpm");
}

t_assets    *lvl_init(t_mlx vars)
{
	t_assets *assets;

	assets = malloc(sizeof(t_assets));
	start_assets(assets);
	alloc_assets(assets);
	assets_init(&vars, assets);
	return (assets);
}

int    win_init(t_mlx vars)
{
	vars.mv = 0;
    vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, (20 * vars.lvl->x), (20 * (vars.lvl->y) + 15), "so_long");
	vars.assets = lvl_init(vars);
	vars.items = 0;
	lvl_building(&vars);
	ft_printf(1, "powerof = %d\n", ft_power(vars.mv));
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &key_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.assets->bg->img, (17 * vars.lvl->x), (20 * (vars.lvl->y)));
	mlx_string_put(vars.mlx, vars.win, (17 * vars.lvl->x), (20 * (vars.lvl->y) + 10), 0xFFFFFFFF, ft_itoa(vars.mv));
    mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	free_global(&vars);
    return (0);
}
