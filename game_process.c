#include "so_long.h"

void    win_init(void)
{
    t_mlxp vars;
    
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 360, "so_long");
    mlx_loop(vars.mlx);
    return ;
}