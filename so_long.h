/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:39:10 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/24 20:15:19 by ccosta-c         ###   ########.fr       */
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
#include<time.h>

#define WALL_PATH "./assets/wall.xpm"
#define	FLOOR_PATH "./assets/floor.xpm"
#define COLECTIBLE_PATH "./assets/collectible.xpm"
#define DOOR_CLOSED_PATH "./assets/door_closed.xpm"
#define DOOR_OPEN_PATH "./assets/door_open.xpm"
#define IDLE_1 "./assets/idle_1.xpm"
#define IDLE_2 "./assets/idle_2.xpm"
#define IDLE_3 "./assets/idle_3.xpm"
#define IDLE_4 "./assets/idle_4.xpm"
#define ENEMY_1 "./assets/enemy_1.xpm"
#define ENEMY_2 "./assets/enemy_2.xpm"
#define ENEMY_3 "./assets/enemy_3.xpm"
#define ENEMY_4 "./assets/enemy_4.xpm"

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
	int	exit_x;
	int	exit_y;
}	t_mapcheck;

typedef struct s_windows
{
	void		*mlx_ptr;
    void		*win_ptr;
	int			x_player;
	int			y_player;
	int			x_size;
	int			y_size;
	int			x_exit;
	int			y_exit;
	int			collected;
	int			nbr_collectibles;
	int			moves;
	char		**render_array;
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
	void		*door_open;
	int			do_width;
	int			do_height;
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
	void		*enemy_1;
	int			enemy_1_height;
	int			enemy_1_width;
	void		*enemy_2;
	int			enemy_2_height;
	int			enemy_2_width;
	void		*enemy_3;
	int			enemy_3_height;
	int			enemy_3_width;
	void		*enemy_4;
	int			enemy_4_height;
	int			enemy_4_width;

}	t_windows;

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
int				handle_render(int keysym, t_windows *data);
int				handle_no_event(void *data);
void			initialize(t_windows *windows);
void			player_animation(t_windows *windows, int x, int i, int j);
void			change_array(t_windows *windows, int x, int y, char chr);
int				check_move(t_windows *windows, char c);
char			*put_text(char *text, int nbr);
void			end_game(t_windows *windows);
void			enemy_animation(t_windows *windows, int x, int i, int j);
int				check_enemy_move(t_windows *windows, char c);
void 			change_enemies(t_windows *windows, char one, char two);
int    			random_generator(void);