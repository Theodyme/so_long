#include "so_long.h"

void	replace_asset(t_mlx *vars)
{
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	else if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->exit->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	else if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->start->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	else if (vars->lvl->map[vars->ppos_y][vars->ppos_x] == 'C')
	{
		vars->lvl->map[vars->ppos_y][vars->ppos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->bg->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	}
}

int			move_up(t_mlx *vars)
{
	if (vars->lvl->map[vars->ppos_y - 1][vars->ppos_x] == 'E' && vars->items == 0)
	{
		ft_printf(1, "you won ! items = %d\n", vars->items);
		exit(free_global(vars, 1));
	}
	if (vars->lvl->map[vars->ppos_y - 1][vars->ppos_x] == '1')
		return (0);
	if (vars->lvl->map[vars->ppos_y - 1][vars->ppos_x] == 'C')
		vars->items -= 1;
	replace_asset(vars);
	vars->ppos_y -= 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	vars->mv += 1;
	return (0);
}

int			move_down(t_mlx *vars)
{
	if (vars->lvl->map[vars->ppos_y + 1][vars->ppos_x] == 'E' && vars->items == 0 )
	{
		ft_printf(1, "you won ! items = %d\n", vars->items);
		exit(free_global(vars, 1));
	}
	if (vars->lvl->map[vars->ppos_y + 1][vars->ppos_x] == '1')
		return (0);
	if (vars->lvl->map[vars->ppos_y + 1][vars->ppos_x] == 'C')
		vars->items -= 1;
	replace_asset(vars);
	vars->ppos_y += 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	vars->mv += 1;
	return (0);
}

int			move_left(t_mlx *vars)
{
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x - 1] == 'E' && vars->items == 0)
	{
		ft_printf(1, "you won ! items = %d\n", vars->items);
		exit(free_global(vars, 1));
	}
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x - 1] == '1')
		return (0);
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x - 1] == 'C')
		vars->items -= 1;
	replace_asset(vars);
	vars->ppos_x -= 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	vars->mv += 1;
	return (0);
}

int			move_right(t_mlx *vars)
{
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x + 1] == 'E' && vars->items == 0)
	{
		ft_printf(1, "you won ! items = %d\n", vars->items);
		exit(free_global(vars, 1));
	}
	if (vars->lvl->map[vars->ppos_y][vars->ppos_x + 1] == '1')
		return (0);
 	if (vars->lvl->map[vars->ppos_y][vars->ppos_x + 1] == 'C')
		vars->items -= 1;
	replace_asset(vars);
	vars->ppos_x += 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->assets->chara->img, (vars->ppos_x * SIZE), (vars->ppos_y * SIZE));
	vars->mv += 1;
	return (0);
}
