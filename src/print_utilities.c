#include "so_long.h"

void    mapprinter(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        ft_printf(1, "%s", map[i]);
        i++;
    }
	ft_printf(1, "\n");
    return ;
}
