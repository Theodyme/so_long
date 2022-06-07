/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:49:11 by flplace           #+#    #+#             */
/*   Updated: 2022/06/07 14:11:39 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <unistd.h>

int				ft_checkbase(char *base);
int				ft_putnbr_uint(int fd, unsigned int nbr);
int				ft_putptr(int fd, size_t hex, char *base);
int				ft_putstr(int fd, char *s);
int				ft_putnbr_base(int fd, int nbr, char *base);
int				ft_putnbr_hex(int fd, unsigned int n, char *base);
void			ft_putchar(int fd, char c);
size_t			ft_strlen(const char *str);

#endif
