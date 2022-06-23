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

	while(map[i])
		free(map[i++]);
	free(map);
	return (0);
}

int		free_data(t_data *data)
{
	free(data->img);
	free(data->addr);
	free(data);
	return (0);
}

int		free_assets(t_assets *assets)
{
	free_data(assets->chara);
	free_data(assets->wall);
	free_data(assets->bg);
	free_data(assets->exit);
	free_data(assets->item);
	free_data(assets->start);
	return (0);
}

int		free_global(t_mlx *vars)
{
	free_map(vars->lvl->map);
	free(vars->lvl);
	free_assets(vars->assets);
	free(vars->assets);
	free(vars->win);
	free(vars->mlx);
	return(0);
}
