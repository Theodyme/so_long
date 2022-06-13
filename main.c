/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:18 by flplace           #+#    #+#             */
/*   Updated: 2022/06/13 17:58:43 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errorprinter(int flag)
{
	if (flag == 1)
		ft_printf(2, "error: no env variable.");
	else if (flag == 2)
		ft_printf(2, "error: map file incorrect.");
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char **map;
	int fd;
	int i;

	map = NULL;
	i = 0;
	(void)ac;
	if (!env)
		return (errorprinter(1));
	if (get_map(av[1]) == 1)
		return (errorprinter(2));
	map = map_init(av[1]);
	fd = open(av[1], O_RDONLY);
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	mapprinter(map);
	win_init();
	return (0);
}

/*
	BY THE WAY, format wise and for the organisation of this project
	and before you push anything, please check that:
		- you have headers everywhere
		- no unauthorized function
		- makefile in your library (would be really awesome if you find out how to
			compile your gnl, ft_printf, lib utilities and mlx at once. I mean throw
			everything in a directory and make 'em all together please, just google 
			to know if it's optimal to use plural makefiles before you do)
		- pass the norminette before pushing
		- check for duplicated functions in your header file, it happened before
		- organize your header file
		- check for memory leaks AND trace your fds since you're opening stuff
			 - gnl included - you didn't valgrind that shit, I know you dude
		- try to keep a trace of your functions, you don't want wandering unused
			functions, even if they're declared in your header file, it's not
			clean
		- destroy any printing function you don't need at the end.

    BREAKING INTO STEPS:
	to read the map, we may need:
		1) open() the file
		2) maybe you need to alloc the map first. if that's the case, you should maybe
			have a function counting the lines you'll need. I think gnl will alloc the
			lines themselves on its own.
		3) read line by line with gnl and store them in a char **map
		4) check the map format (strlen may be useful)

    PARSING properly speaking 
        x check if env variable exists
        x check if the map file has the correct extension format (.ber)
        x check if argv isn't empty
        o check if the map is empty
        o check if you can't open the map
        o check if the map is a file or a directory





*/