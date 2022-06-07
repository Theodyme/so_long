/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:49:31 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:17:02 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putnbr_hex(int fd, unsigned int n, char *base)
{
	int				cnt;
	unsigned int	baselen;

	cnt = 0;
	baselen = ft_strlen(base);
	if (ft_checkbase(base))
	{
		if (n >= (unsigned int)baselen)
			cnt += ft_putnbr_hex(fd, n / baselen, base);
		ft_putchar(fd, base[(n % baselen)]);
		cnt++;
	}
	return (cnt);
}
