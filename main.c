/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:18 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 15:04:13 by flplace          ###   ########.fr       */
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
	(void)ac;
	if (!env)
		return (errorprinter(1));
	if (get_map(av[1]) == 1)
		return (errorprinter(2));
	return (0);
}
