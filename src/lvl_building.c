/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:22:31 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:34:43 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	asset_printer(char c, t_mlx *vars, int posx, int posy)
{
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets->wall->img, posx, posy);
	else if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets->bg->img, posx, posy);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets->exit->img, posx, posy);
	else if (c == 'C')
	{
		vars->items += 1;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets->item->img, posx, posy);
	}
}

void	line_building(t_mlx *vars, char *line, int posy)
{
	int		i;
	int		posx;

	i = 0;
	posx = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'E'
			|| line[i] == 'C')
			asset_printer(line[i], vars, posx, posy);
		else if (line[i] == 'P')
		{
			vars->ppos_x = i;
			vars->ppos_y = posy / TILESIZE;
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->assets->start->img, posx, posy);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->assets->chara->img, posx, posy);
		}
		posx += TILESIZE;
		i++;
	}
}

void	lvl_building(t_mlx *vars)
{
	int	i;

	i = 0;
	vars->items = 0;
	while (vars->lvl->map[i])
	{
		line_building(vars, &vars->lvl->map[i][0], (i * TILESIZE));
		i++;
	}
}
