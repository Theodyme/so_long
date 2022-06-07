/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wrappers_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:15:55 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:08:41 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrapper_u(va_list *ap, int fd)
{
	return (ft_putnbr_uint(fd, va_arg(*ap, unsigned int)));
}

int	wrapper_lx(va_list *ap, int fd)
{
	return (ft_putnbr_hex(fd, va_arg(*ap, unsigned int), "0123456789abcdef"));
}

int	wrapper_ux(va_list *ap, int fd)
{
	return (ft_putnbr_hex(fd, va_arg(*ap, unsigned int), "0123456789ABCDEF"));
}
