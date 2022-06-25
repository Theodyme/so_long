/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:22:13 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:39:05 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	start_assets(t_assets *assets)
{
	assets->chara = NULL;
	assets->wall = NULL;
	assets->bg = NULL;
	assets->exit = NULL;
	assets->item = NULL;
	assets->start = NULL;
	assets->black = NULL;
	return (0);
}

int	alloc_assets(t_assets *assets)
{
	assets->chara = malloc(sizeof(t_data));
	assets->wall = malloc(sizeof(t_data));
	assets->bg = malloc(sizeof(t_data));
	assets->exit = malloc(sizeof(t_data));
	assets->item = malloc(sizeof(t_data));
	assets->start = malloc(sizeof(t_data));
	assets->black = malloc(sizeof(t_data));
	if (!(assets->chara && assets->wall && assets->bg && assets->exit
			&& assets->item && assets->start && assets->black))
		return (1);
	return (0);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i])
		free(map[i++]);
	if (map)
		free(map);
	return (0);
}

int	free_assets(t_mlx *vars)
{
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
	free_data(vars->assets->black, vars->mlx);
	free(vars->assets->black);
	return (0);
}

int	free_global(t_mlx *vars, int return_val)
{
	free_map(vars->lvl->map);
	free(vars->lvl);
	if (vars->assets)
		free_assets(vars);
	free(vars->assets);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (return_val);
}
