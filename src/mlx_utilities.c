/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:22:15 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:41:36 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_data(t_data *data, void *mlx)
{
	if (data->img == NULL)
		return (0);
	mlx_destroy_image(mlx, data->img);
	return (0);
}

int	destroy_win(t_mlx *vars)
{
	(void)vars;
	exit(free_global(vars, 1));
	return (0);
}

int	handle_no_event(void *vars)
{
	(void)vars;
	return (0);
}

void	display_moves(t_mlx *vars)
{
	char	*count;

	count = ft_itoa(vars->mv);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->black->img,
		(17 * vars->lvl->x), (TILESIZE * (vars->lvl->y)));
	mlx_string_put(vars->mlx, vars->win, (17 * vars->lvl->x),
		(TILESIZE * (vars->lvl->y) + 10), 0xFFFFFFFF, count);
	free(count);
}

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == XK_Escape)
		destroy_win(vars);
	else if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
	{
		move_up(vars);
	}
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		move_down(vars);
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		move_left(vars);
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		move_right(vars);
	display_moves(vars);
	return (0);
}
