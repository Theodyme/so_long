/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:12:12 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:17:13 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putnbr_uint(int fd, unsigned int nbr)
{
	int				cnt;

	cnt = 0;
	if (nbr >= 10)
		cnt += ft_putnbr_uint(fd, nbr / 10);
	ft_putchar(fd, (nbr % 10) + '0');
	cnt++;
	return (cnt);
}
