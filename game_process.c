#include "so_long.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void    win_init(t_mlx vars)
{
	t_data	data;
	int	height;
	int	width;

	height = 20;
	width = 20;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	data.img = mlx_new_image(vars.mlx, 20, 20);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.end);
	data.img = mlx_xpm_file_to_image(vars.mlx, "./character.xpm", &width, &height);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 150, 300);
    mlx_loop(vars.mlx);
    return ;
}
