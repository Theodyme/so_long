/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:18 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 17:41:16 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	errorprinter(int flag)
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
		ft_printf(2,
			"\e[1;91mError\n> \e[22;91mdoesn't start /w correct walls.\e[22;91m\n");
	else if (flag == 8)
		ft_printf(2, "\e[1;91mError\n> \e[22;91mtoo many start.\e[22;91m\n");
	return (1);
}

int	env_check(char **env)
{
	int	i;

	if (!*env)
	{
		ft_printf(2, "\e[1;91mError\n> \e[22;91menv unreachable.\e[22;91m\n");
		return (1);
	}
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("DISPLAY", env[i], 7))
			return (0);
		i++;
	}
	ft_printf(2, "\e[1;91mError\n> \e[22;91mDISPLAY unreachable.\e[22;91m\n");
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_mlx	vars;

	if (env_check(env))
		return (0);
	if (ac == 1 || get_map(av[1]) != 0)
		return (errorprinter(get_map(av[1])));
	vars.lvl = map_init(av[1]);
	if (vars.lvl->map == NULL || vars.lvl == NULL
		|| !(vars.lvl->y))
	{
		free_map(vars.lvl->map);
		free(vars.lvl);
		return (1);
	}
	vars.lvl->x = ft_strlen(vars.lvl->map[0]) - 1;
	if (format_checker(*vars.lvl))
	{
		free_map(vars.lvl->map);
		free(vars.lvl);
		return (1);
	}
	win_init(&vars);
	free_global(&vars, 0);
	return (0);
}
