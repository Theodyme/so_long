#include "so_long.h"

int y_count(char *file)
{
    int fd;
    int i;

    fd = open(file, O_RDONLY);
    if (fd == -1)
	{
		ft_printf(2, "\e[1;91mError\n> \e[22;91mcouldn't open file.\e[22;91m\n");
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

t_map    map_init(char *file)
{
	t_map lvl;

    lvl.y = y_count(file);
    if (lvl.y == -1)
	{
		lvl.map = NULL;
        return (lvl);
	}
	lvl.map = (char **)malloc(sizeof(char *) * (lvl.y + 1));
    lvl.map[lvl.y] = NULL;
	map_builder(file, lvl.map);
    return (lvl);
}
