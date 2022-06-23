/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:18 by flplace           #+#    #+#             */
/*   Updated: 2022/06/23 22:25:02 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int errorprinter(int flag)
{
	if (flag == 2)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mmap file incorrect.\e[22;91m\n");
	else if (flag == 3)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mfile is a directory.\e[22;91m\n");
	else if (flag == 4)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mexit missing.\e[22;91m\n");
	else if (flag == 5)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mitem missing.\e[22;91m\n");
	else if (flag == 6)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mstarting point missing.\e[22;91m\n");
	else if (flag == 7)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mwalls missing.\e[22;91m\n");
	return (1);
}

int main(int ac, char **av)
{
	t_mlx vars;
	// void *img;

	if (ac == 1 || get_map(av[1]) != 0)
		return (errorprinter(get_map(av[1])));
	vars.lvl = map_init(av[1]);
	if (vars.lvl->map == NULL)
		return (1);
	vars.lvl->x = ft_strlen(vars.lvl->map[0]) - 1;
	if (format_checker(*vars.lvl))
		return (1);
	mapprinter(vars.lvl->map);
	win_init(vars);
	free_map(vars.lvl->map);
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
		5) !!! if there is two starting point ???

	PARSING properly speaking
		x check if env variable exists
		x check if the map file has the correct extension format (.ber)
		x check if argv isn't empty
		o check if the map is empty
		x check if you can't open the map
		o check if the map is a file or a directory

*/
