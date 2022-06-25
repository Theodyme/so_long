/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:12 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 15:51:57 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	name_checker(char *filename)
{
	int	i;

	i = ft_strlen(filename) - 4;
	if (i <= 4)
		return (1);
	if (ft_strcmp((filename + i), ".ber") != 0)
		return (1);
	return (0);
}

int	charsetchecker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_charset("01CEP\n\0", map[i][j]) == 0)
			{
				ft_printf(2,
					"\e[1;91mError\n> \e[22;91mwrong charset in map.\e[22;91m\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_map(char *filename)
{
	if (!filename)
		return (2);
	if (name_checker(filename) == 1)
		return (2);
	if (is_directory(filename) == 1)
		return (3);
	return (0);
}

int	format_checker(t_map lvl)
{
	if (charsetchecker(lvl.map) == 1)
		return (1);
	if (char_count(lvl.map, 'E') < 1)
		return (errorprinter(4));
	if (char_count(lvl.map, 'C') < 1)
		return (errorprinter(5));
	if (char_count(lvl.map, 'P') < 1)
		return (errorprinter(6));
	if (wall_checking(lvl) == 1)
		return (errorprinter(7));
	return (0);
}
