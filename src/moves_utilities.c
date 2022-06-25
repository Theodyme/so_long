/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:22:40 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:49:26 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_move(t_mlx *vars, int y, int x)
{
	if (vars->lvl->map[vars->ppos_y + y][vars->ppos_x + x] == 'E'
		&& vars->items == 0)
	{
		ft_printf(1, "you won ! total moves = %d\n", (vars->mv + 1));
		exit(free_global(vars, 1));
	}
	if (vars->lvl->map[vars->ppos_y + y][vars->ppos_x + x] == '1')
		return ;
	if (vars->lvl->map[vars->ppos_y + y][vars->ppos_x + x] == 'C')
		vars->items -= 1;
	replace_asset(vars);
	vars->ppos_y += y;
	vars->ppos_x += x;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img,
		(vars->ppos_x * TILESIZE), (vars->ppos_y * TILESIZE));
}

int	move_up(t_mlx *vars)
{
	player_move(vars, -1, 0);
	vars->mv += 1;
	return (0);
}

int	move_down(t_mlx *vars)
{
	player_move(vars, +1, 0);
	vars->mv += 1;
	return (0);
}

int	move_left(t_mlx *vars)
{
	player_move(vars, 0, -1);
	vars->mv += 1;
	return (0);
}

int	move_right(t_mlx *vars)
{
	player_move(vars, 0, +1);
	vars->mv += 1;
	return (0);
}
