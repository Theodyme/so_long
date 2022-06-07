/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:13 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:14:10 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../library/library.h"
# include <unistd.h>

typedef int	(*t_type)(va_list *ap, int fd);

typedef struct t_fn
{
	char	flag;
	t_type	function;
}		t_fn;

int	ft_printf(int fd, const char *input, ...);
int	ft_process_args(int fd, va_list *ap, char flag);
int	wrapper_c(va_list *ap, int fd);
int	wrapper_i(va_list *ap, int fd);
int	wrapper_lx(va_list *ap, int fd);
int	wrapper_p(va_list *ap, int fd);
int	wrapper_s(va_list *ap, int fd);
int	wrapper_u(va_list *ap, int fd);
int	wrapper_ux(va_list *ap, int fd);

#endif
