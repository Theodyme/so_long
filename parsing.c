/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:12 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 15:05:21 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		namechecker(char *av)
{
	int i;

	i = ft_strlen(av) - 4;
	if (i <= 4)
		return (1);
	if (ft_strcmp((av + i), ".ber") != 0)
		return (1);
	return (0);
}

int		get_map(char *av)
{
	// int	map;
	// ft_printf(0, "the path is: %s\n", av);
	if (!av)
		return (1);
	if (namechecker(av) == 1)
		return (1);
	// map = open(av, O_RDONLY, 0777);
	return (0);
}
