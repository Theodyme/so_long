#include "so_long.h"

int y_count(char *file)
{
    int fd;
    int i;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
    i = 0;
    while (get_next_line(fd))
        i++;
    close(fd);
    return (i);
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
    return (map);
}