#include "so_long.h"

int		is_charset(char *charset, char b)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i++] == b)
			return (1);
	}
	return (0);
}

int		is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int		char_count_line(char *line, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

int		char_count(char **map, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (map[i])
	{
		cnt += char_count_line(map[i], c);
		i++;
	}
	return (cnt);
}

int		wall_checking(t_map lvl)
{
	int i;

	i = 0;
	if (char_count_line(lvl.map[0], '1') != lvl.x || char_count_line(lvl.map[lvl.y - 1], '1') != lvl.x)
		return (1);
	while (lvl.map[i])
	{
		if (lvl.map[i][0] != '1' || lvl.map[i][lvl.x - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
