/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:22:06 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:26:08 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	data_init(t_data *data, char *path, void *mlx)
{
	int	size;

	size = 20;
	data->img = mlx_xpm_file_to_image(mlx, path, &size, &size);
}

int	assets_init(t_mlx *vars)
{
	data_init(vars->assets->chara, CHARA, vars->mlx);
	data_init(vars->assets->wall, WALL, vars->mlx);
	data_init(vars->assets->bg, BG, vars->mlx);
	data_init(vars->assets->exit, EXIT, vars->mlx);
	data_init(vars->assets->item, ITEM, vars->mlx);
	data_init(vars->assets->start, START, vars->mlx);
	data_init(vars->assets->black, BLACK, vars->mlx);
	if (vars->assets->chara->img != NULL && vars->assets->wall->img != NULL
		&& vars->assets->bg->img != NULL && vars->assets->exit->img != NULL
		&& vars->assets->item->img != NULL && vars->assets->start->img != NULL
		&& vars->assets->black->img != NULL)
		return (0);
	return (1);
}

void	lvl_init(t_mlx *vars)
{
	vars->assets = malloc(sizeof(t_assets));
	start_assets(vars->assets);
	if (alloc_assets(vars->assets) == 1)
		exit(free_global(vars, 1));
	if (assets_init(vars) == 1)
		exit(free_global(vars, 1));
}

int	game_launcher(t_mlx *vars)
{
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, &key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 5, destroy_win, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->black->img,
		(17 * vars->lvl->x), (TILESIZE * (vars->lvl->y)));
	mlx_string_put(vars->mlx, vars->win, (17 * vars->lvl->x),
		(TILESIZE * (vars->lvl->y) + 10), 0xFFFFFFFF, "0");
	mlx_loop(vars->mlx);
	return (0);
}

int	win_init(t_mlx *vars)
{
	vars->mv = 0;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (1);
	vars->win = mlx_new_window(vars->mlx, (TILESIZE * vars->lvl->x),
			(TILESIZE * (vars->lvl->y) + 15), "so_long");
	if (vars->win == NULL)
		return (1);
	lvl_init(vars);
	vars->items = 0;
	lvl_building(vars);
	game_launcher(vars);
	free_global(vars, 1);
	return (0);
}
