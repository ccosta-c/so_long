/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:39:10 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 18:40:56 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <X11/X.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

#define WALL_PATH "./assets/wall.xpm"
#define	FLOOR_PATH "./assets/floor.xpm"
#define COLECTIBLE_PATH "./assets/collectible.xpm"
#define DOOR_CLOSED_PATH "./assets/door_closed.xpm"
#define IDLE_1 "./assets/idle_1.xpm"
#define IDLE_2 "./assets/idle_2.xpm"
#define IDLE_3 "./assets/idle_3.xpm"
#define IDLE_4 "./assets/idle_4.xpm"

typedef struct s_coordinates
{
	int x;
	int y;
}	t_coordinates;

typedef struct s_mapcheck
{
	int x;
	int y;
	int collectibles;
	int exits;
	int found_exit;
	int collectibles_found;
	int players;
}	t_mapcheck;

typedef struct s_windows
{
	void		*mlx_ptr;
    void		*win_ptr;
	int			x_player;
	int			y_player;
	int			x_size;
	int			y_size;
	void		*floor;
	int			floor_width;
	int			floor_height;
	void		*wall;
	int			wall_width;
	int			wall_height;
	void		*collectible;
	int			collectible_width;
	int			collectible_height;
	void		*door_closed;
	int			dc_width;
	int			dc_height;
	void		*idle_1;
	int			idle_1_height;
	int			idle_1_width;
	void		*idle_2;
	int			idle_2_height;
	int			idle_2_width;
	void		*idle_3;
	int			idle_3_height;
	int			idle_3_width;
	void		*idle_4;
	int			idle_4_height;
	int			idle_4_width;
	char		**render_array;
	t_mapcheck 	*map_data;
}	t_windows;


typedef struct s_xpm
{
	void	*xpm_ptr;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_texture
{
	t_xpm	tile;
	t_xpm	floor;
	t_xpm	coins;
	t_xpm	exit;
	t_xpm	player;
}	t_texture;

int				get_height(char *file);
int 			get_width(char *file);
int				get_map_size(t_windows *windows, char *file);
char			**convert_map_to_array(t_windows windows, char *file);
void			ft_print_array (char **array);
int				check_map_info(char **map, t_mapcheck *data);
int				map_checker(char **map, t_mapcheck data, t_windows windows);
int				check_quant(char **map, t_mapcheck *data);
int				check_borders(char **map, t_windows windows);
int				draw_windows(t_windows *windows);
int				check_line(char **map, int x, int y, t_windows windows);
int				check_row(char **map, int x, int y, t_windows windows);
void			free_array(char **array, int y);
int				draw_map(t_windows *windows);
int				handle_keypress(int keysym, t_windows *data);
int				handle_no_event(void *data);
void			initialize(t_windows *windows);
void			player_animation(t_windows *windows, int x, int i, int j);
void			change_array(t_windows *windows, int x, int y, char chr);