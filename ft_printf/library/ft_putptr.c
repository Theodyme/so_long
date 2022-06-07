/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:12:31 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:16:43 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putptr(int fd, size_t hex, char *base)
{
	int				cnt;

	cnt = 0;
	if (hex >= 16)
		cnt += ft_putptr(fd, hex / 16, base);
	ft_putchar(fd, base[(hex % 16)]);
	cnt++;
	return (cnt);
}
