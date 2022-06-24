#include "so_long.h"

int		start_assets(t_assets *assets)
{
	assets->chara = NULL;
	assets->wall = NULL;
	assets->bg = NULL;
	assets->exit = NULL;
	assets->item = NULL;
	assets->start = NULL;
	return (0);
}

int		alloc_assets(t_assets *assets)
{
	assets->chara = malloc(sizeof(t_data));
	ft_printf(1, "allocating %p\n", assets->chara);
	assets->wall = malloc(sizeof(t_data));
	assets->bg = malloc(sizeof(t_data));
	assets->exit = malloc(sizeof(t_data));
	assets->item = malloc(sizeof(t_data));
	assets->start = malloc(sizeof(t_data));
	return (0);
}

int		free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i])
		free(map[i++]);
	if (map)
		free(map);
	return (0);
}

int		free_data(t_data *data, void *mlx)
{
	mlx_destroy_image(mlx, data->img);
	// (void)mlx;
	// free(data->img);
	// free(data->addr);
	// free(data);
	return (0);
}

int		free_assets(t_mlx *vars)
{
	ft_printf(1, "FREEING ASSETS %p\n", vars->assets->chara);
	free_data(vars->assets->chara, vars->mlx);
	free(vars->assets->chara);
	free_data(vars->assets->wall, vars->mlx);
	free(vars->assets->wall);
	free_data(vars->assets->bg, vars->mlx);
	free(vars->assets->bg);
	free_data(vars->assets->exit, vars->mlx);
	free(vars->assets->exit);
	free_data(vars->assets->item, vars->mlx);
	free(vars->assets->item);
	free_data(vars->assets->start, vars->mlx);
	free(vars->assets->start);
	return (0);
}

int		free_global(t_mlx *vars, int return_val)
{
	free_map(vars->lvl->map);
	free(vars->lvl);
	free_assets(vars);
	free(vars->assets);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return(return_val);
}
