#include "so_long.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

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

t_assets    *lvl_init(t_mlx vars, t_map lvl)
{
	t_assets *assets;

	assets = malloc(sizeof(t_assets));
	start_assets(assets);
	alloc_assets(assets);
	assets_init(&vars, assets);
	ft_printf(1, "chara = %p\n", assets->chara->addr);
	(void)lvl;
	// lvl_building(&vars, lvl);
	// mlx_put_image_to_window(vars.mlx, vars.win, assets.wall.img, 0, 0);
	return (assets);
}

int    win_init(t_mlx vars, t_map lvl)
{
    vars.mlx = mlx_init();
	// (void)lvl;
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, (20 * lvl.x), (20 * lvl.y), "so_long");
	// vars.assets = assets_init(vars);
	vars.assets = lvl_init(vars, lvl);
	lvl_building(&vars, lvl);
	ft_printf(1, "assets = %p\n", vars.assets->chara->img);
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &key_hook, &vars);
    mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
    return (0);
}
