#include "so_long.h"

int y_count(char *file)
{
    int fd;
    int i;

    fd = open(file, O_RDONLY);
    if (fd == -1)
	{
		ft_printf(2, "error: couldn't open file.");
        return (-1);
	}
	i = 0;
    while (get_next_line(fd))
        i++;
    close(fd);
    return (i);
}

char	**map_builder(char *file, char **map)
{
	int i;
	int	l;
	int	fd;

	i = 0;
	l = y_count(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "error: couldn't open file.");
		return (NULL);
	}
	map[i++] = get_next_line(fd);
	while (l != 0)
	{
		map[i++]= get_next_line(fd);
		l--;
	}
	close(fd);
	return (map);
}

char    **map_init(char *file)
{
    char **map;
    int y;

    y = y_count(file);
    if (y == -1)
        return (NULL);
    map = (char **)malloc(sizeof(char *) * (y + 1));
    map[y] = NULL;
	map_builder(file, map);
    return (map);
}
