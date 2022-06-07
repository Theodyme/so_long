/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:55 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:16:54 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putnbr_base(int fd, int nbr, char *base)
{
	unsigned int	n;
	int				cnt;
	int				baselen;

	cnt = 0;
	n = 0;
	baselen = ft_strlen(base);
	if (ft_checkbase(base))
	{
		if (nbr < 0)
		{
			ft_putchar(fd, '-');
			cnt++;
			n = -nbr;
		}
		else
			n = nbr;
		if (n >= (unsigned int)baselen)
			cnt += ft_putnbr_base(fd, n / baselen, base);
		ft_putchar(fd, base[(n % baselen)]);
		cnt++;
	}
	return (cnt);
}
