#include "so_long.h"

// void	success_exit(t_mlx vars)
// {
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->exit->img, (vars->ppos_x * 20), (vars->ppos_y * 20));
// }

void data_init(t_data *data, char *path, void *mlx)
{
	int size;

	size = 20;
	data->img = mlx_xpm_file_to_image(mlx, path, &size, &size);
}

// VERIFIER SI LES ASSETS SONT OUVRABLE ET LE PROTEGER

void	assets_init(t_mlx *vars)
{
	data_init(vars->assets->chara, "./character.xpm", vars->mlx);
	data_init(vars->assets->wall, "./wall.xpm", vars->mlx);
	data_init(vars->assets->bg, "./bg.xpm", vars->mlx);
	data_init(vars->assets->exit, "./exit.xpm", vars->mlx);
	data_init(vars->assets->item, "./item.xpm", vars->mlx);
	data_init(vars->assets->start, "./start.xpm", vars->mlx);
}

void    lvl_init(t_mlx *vars)
{
	vars->assets = malloc(sizeof(t_assets));
	start_assets(vars->assets);
	alloc_assets(vars->assets);
	assets_init(vars);
}

int    win_init(t_mlx *vars)
{
	// char * count;

	vars->mv = 0;
	// count = ft_itoa(vars->mv);
	// ft_strlen(count);
    vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (1);
	vars->win = mlx_new_window(vars->mlx, (SIZE * vars->lvl->x), (SIZE * (vars->lvl->y) + 15), "so_long");
	lvl_init(vars);
	vars->items = 0;
	lvl_building(vars);
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, &key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 5, destroy_win, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img, (17 * vars->lvl->x), (SIZE * (vars->lvl->y)));
	mlx_string_put(vars->mlx, vars->win, (17 * vars->lvl->x), (SIZE * (vars->lvl->y) + 10), 0xFFFFFFFF, ft_itoa(vars->mv));
	// free(count);
    mlx_loop(vars->mlx);
	free_global(vars, 1);
    return (0);
}
