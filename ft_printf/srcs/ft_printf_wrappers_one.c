/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wrappers_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:15:41 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:10:07 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrapper_c(va_list *ap, int fd)
{
	ft_putchar(fd, va_arg(*ap, int));
	return (1);
}

int	wrapper_s(va_list *ap, int fd)
{
	return (ft_putstr(fd, va_arg(*ap, char *)));
}

int	wrapper_i(va_list *ap, int fd)
{
	return (ft_putnbr_base(fd, va_arg(*ap, int), "0123456789"));
}

int	wrapper_p(va_list *ap, int fd)
{
	write(1, "0x", 2);
	return (2 + ft_putptr(fd, (size_t)va_arg(*ap, void *), "0123456789abcdef"));
}
