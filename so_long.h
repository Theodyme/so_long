/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:14 by flplace           #+#    #+#             */
/*   Updated: 2022/06/14 15:37:18 by flplace          ###   ########.fr       */
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

typedef struct s_map
{
    char	**map;
    int		y;
	int		x;
}				t_map;

/*		error handler				*/
int		errorprinter(int flag);

/*		parsing						*/
int		char_count(char **map, char c);
int		char_count_line(char *line, char c);
int		charsetchecker(char **map);
int		format_checker(t_map lvl);
int		get_map(char *filename);
int		is_charset(char *charset, char b);
int		is_directory(char *filename);
int		name_checker(char *filename);
int		wall_checking(t_map lvl);

/*      game process                */
void    win_init(void);

/*      map building                */
char    **map_init(char *file);
char	**map_builder(char *file, char **map);
int     y_count(char *file);

/*		utils						*/
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strcmp(const char *s1, const char *s2);

/*      those needs to go           */
void    mapprinter(char **map);


#endif
