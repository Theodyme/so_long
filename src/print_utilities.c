/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:22:46 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:52:54 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	replace_asset(t_mlx *vars)
{
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img,
			(vars->ppos_x * TILESIZE), (vars->ppos_y * TILESIZE));
	else if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->exit->img,
			(vars->ppos_x * TILESIZE), (vars->ppos_y * TILESIZE));
	else if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->start->img,
			(vars->ppos_x * TILESIZE), (vars->ppos_y * TILESIZE));
	else if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == 'C')
	{
		vars->lvl->map[vars->ppos_y][vars->ppos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img,
			(vars->ppos_x * TILESIZE), (vars->ppos_y * TILESIZE));
	}
}

void	mapprinter(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf(1, "%s", map[i]);
		i++;
	}
	ft_printf(1, "\n");
	return ;
}
