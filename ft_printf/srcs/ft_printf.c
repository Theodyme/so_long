/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:10:05 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:12:30 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_args(int fd, va_list *ap, char flag)
{
	const t_fn	library[9] = {
	{.flag = 'c', .function = &wrapper_c},
	{.flag = 's', .function = &wrapper_s},
	{.flag = 'p', .function = &wrapper_p},
	{.flag = 'd', .function = &wrapper_i},
	{.flag = 'i', .function = &wrapper_i},
	{.flag = 'u', .function = &wrapper_u},
	{.flag = 'x', .function = &wrapper_lx},
	{.flag = 'X', .function = &wrapper_ux},
	};
	int			i;

	i = 0;
	if (flag == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	while (flag != library[i].flag && library[i].flag)
		i++;
	if (library[i].flag != '\0')
		return (library[i].function(ap, fd));
	return (0);
}

int	ft_printf(int fd, const char *input, ...)
{
	va_list	ap;
	int		writ;

	va_start(ap, input);
	writ = 0;
	while (*input)
	{
		if (*input == '%')
		{
			writ += ft_process_args(fd, &ap, *(++input));
		}
		else
		{
			write(fd, input, 1);
			writ++;
		}
		input++;
	}
	va_end(ap);
	return (writ);
}
