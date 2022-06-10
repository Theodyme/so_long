/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:12 by flplace           #+#    #+#             */
/*   Updated: 2022/06/10 16:20:16 by theophane        ###   ########.fr       */
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

// int		charsetchecker(char **map)
// {

// }

int		get_map(char *av)
{
	if (!av)
		return (1);
	if (namechecker(av) == 1)
		return (1);
	return (0);
}
