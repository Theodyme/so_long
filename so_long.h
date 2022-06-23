/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:14 by flplace           #+#    #+#             */
/*   Updated: 2022/06/24 01:04:57 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "ft_printf/srcs/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
}				t_data;

typedef struct	s_assets {
	t_data	*chara;
	t_data	*wall;
	t_data	*bg;
	t_data	*exit;
	t_data	*item;
	t_data	*start;
}				t_assets;

typedef struct s_map
{
    char	**map;
    int		y;
	int		x;
}				t_map;

typedef struct s_mlx
{
    void    	*mlx;
    void    	*win;
	t_map		*lvl;
	int			ppos_y;
	int			ppos_x;
	int			items;
	int			mv;
	t_assets	*assets;
}				t_mlx;

/*		error handler&destroyer		*/
int			errorprinter(int flag);
int			free_map(char **map);
int			free_global(t_mlx *vars);
int			free_assets(t_assets *assets);
int			free_data(t_data *data);

/*		parsing						*/
int			char_count(char **map, char c);
int			charsetchecker(char **map);
int			format_checker(t_map lvl);
int			get_map(char *filename);
int			name_checker(char *filename);
int			wall_checking(t_map lvl);

/*		parsing utilities			*/
int			char_count_line(char *line, char c);
int			is_charset(char *charset, char b);
int			is_directory(char *filename);

/*		game utilities				*/
int			destroy_win(t_mlx *vars);
int			handle_no_event(void *vars);
int 		key_hook(int keycode, t_mlx *vars);
int		   	win_init(t_mlx vars);

/*		moves utilities				*/
void	success_exit(t_mlx *vars);
void	replace_asset(t_mlx *vars);
int			move_up(t_mlx *vars);
int			move_down(t_mlx *vars);
int			move_left(t_mlx *vars);
int			move_right(t_mlx *vars);

/*      worldbuilding process		*/
int			start_assets(t_assets *assets);
int			alloc_assets(t_assets *assets);
void		assets_init(t_mlx *vars, t_assets *assets);
t_data		*data_init(t_mlx *vars, char *path);
void    	line_building(t_mlx *vars, char *line, int posy);
void    	lvl_building(t_mlx *vars);
t_assets   	*lvl_init(t_mlx vars);
// void		pixel_put(t_data *data, int x, int y, int color);

/*      **map building              */
t_map   	*map_init(char *file);
char		**map_builder(char *file, char **map);
int     	y_count(char *file);

/*		utils						*/
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_itoa(int nb);
int			ft_power(long nb);

/*      those needs to go           */
void    	mapprinter(char **map);


#endif
