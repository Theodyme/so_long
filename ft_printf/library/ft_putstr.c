/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:13:08 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:16:22 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putstr(int fd, char *s)
{
	int	cnt;

	cnt = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		ft_putchar(fd, *s++);
		cnt++;
	}
	return (cnt);
}
