/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:57:51 by flplace           #+#    #+#             */
/*   Updated: 2022/02/14 18:12:47 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "library.h"

int	ft_checkbase(char *base)
{
	int	i;
	int	j;
	int	baselen;

	i = 0;
	j = 1;
	baselen = ft_strlen(base);
	if (baselen == 0 || baselen == 1)
		return (0);
	while (base[i])
	{
		if (base[i] < 32 || base[i] > 126)
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
