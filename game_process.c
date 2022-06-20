#include "so_long.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

t_data	data_init(t_mlx vars, char *path)
{
	int size;
	t_data data;

	size = 20;
	data.img = mlx_new_image(vars.mlx, 20, 20);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.end);
	data.img = mlx_xpm_file_to_image(vars.mlx, path, &size, &size);
	return (data);
}

t_assets	assets_init(t_mlx vars)
{
	t_assets assets;

	assets.chara = data_init(vars, "./character.xpm");
	assets.wall = data_init(vars, "./wall.xpm");
	assets.bg = data_init(vars, "./bg.xpm");
	assets.exit = data_init(vars, "./exit.xpm");
	assets.item = data_init(vars, "./item.xpm");
	assets.start = data_init(vars, "./start.xpm");
	return (assets);
}

void	lvl_init(t_mlx vars, t_map lvl)
{
	t_assets	assets;

	assets = assets_init(vars);
	lvl_building(vars, lvl, assets);
	// mlx_put_image_to_window(vars.mlx, vars.win, assets.wall.img, 0, 0);
}

void    win_init(t_mlx vars, t_map lvl)
{
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, (20 * lvl.x), (20 * lvl.y), "so_long");
	// vars.win = mlx_new_window(vars.mlx, (500), (20 * lvl.y), "so_long");
	lvl_init(vars, lvl);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, DestroyNotify, 1L << 0, destroy_win, &vars);
    mlx_loop(vars.mlx);
    return ;
}
