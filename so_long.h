/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:14 by flplace           #+#    #+#             */
/*   Updated: 2022/06/13 17:51:07 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf/srcs/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_mlxp
{
    void    *mlx;
    void    *win;
}				t_mlxp;

/*		error handler				*/
int		errorprinter(int flag);

/*		parsing						*/
int		get_map(char *av);
int		namechecker(char *av);
// int     charsetchecker(char **map);

/*      game process                */
void    win_init(void);

/*      map building                */
char    **map_init(char *file);
int     y_count(char *file);

/*		utils						*/
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strcmp(const char *s1, const char *s2);

/*      those needs to go           */
void    mapprinter(char **map);


#endif
