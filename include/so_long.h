/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:55:14 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 17:49:16 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../ft_printf/srcs/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# define TILESIZE 20
# define CHARA "assets/character.xpm"
# define WALL "assets/wall.xpm"
# define BG "assets/bg.xpm"
# define ITEM "assets/item.xpm"
# define EXIT "assets/exit.xpm"
# define START "assets/start.xpm"
# define BLACK "assets/void.xpm"

typedef struct s_data {
	void	*img;
}				t_data;

typedef struct s_assets {
	t_data	*chara;
	t_data	*wall;
	t_data	*bg;
	t_data	*exit;
	t_data	*item;
	t_data	*start;
	t_data	*black;
}				t_assets;

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
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
int			free_global(t_mlx *vars, int return_val);
int			free_assets(t_mlx *vars);
int			free_data(t_data *data, void *mlx);

/*		parsing						*/
int			char_count(char **map, char c);
int			charsetchecker(char **map);
int			format_checker(t_map lvl);
int			get_map(char *filename);
int			name_checker(char *filename);
int			wall_checking(t_map lvl);

/*		parsing utilities			*/
int			env_check(char **env);
int			char_count_line(char *line, char c);
int			is_charset(char *charset, char b);
int			is_directory(char *filename);

/*		game utilities				*/
void		display_moves(t_mlx *vars);
int			game_launcher(t_mlx *vars);
int			destroy_win(t_mlx *vars);
int			handle_no_event(void *vars);
int			key_hook(int keycode, t_mlx *vars);
int			win_init(t_mlx *vars);

/*		moves utilities				*/
void		replace_asset(t_mlx *vars);
void		player_move(t_mlx *vars, int y, int x);
int			move_up(t_mlx *vars);
int			move_down(t_mlx *vars);
int			move_left(t_mlx *vars);
int			move_right(t_mlx *vars);

/*      worldbuilding process		*/
void		asset_printer(char c, t_mlx *vars, int posx, int posy);
int			start_assets(t_assets *assets);
int			alloc_assets(t_assets *assets);
int			assets_init(t_mlx *vars);
void		data_init(t_data *data, char *path, void *mlx);
void		line_building(t_mlx *vars, char *line, int posy);
void		lvl_building(t_mlx *vars);
void		lvl_init(t_mlx *vars);

/*      **map building              */
t_map		*map_init(char *file);
char		**map_builder(char *file, char **map);
int			y_count(char *file);

/*		utils						*/
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		*ft_itoa(int nb);
int			ft_power(long nb);

#endif
