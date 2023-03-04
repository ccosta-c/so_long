/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:39:10 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/03 12:24:09 by ccosta-c         ###   ########.fr       */
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
	int			nbr_collectibles;
	int			collectibles_found;
	int			collected;
	int			exits;
	int			found_exit;
	int			players;
	int			moves;
	int			rand;
	char		**render_array;
	void		*floor;
	int			image_width;
	int			image_height;
	char		*str_moves;
	char		*str_collectibles;
	char		*str_total_collectibles;
	char		*str_join_collectibles;
	void		*wall;
	void		*collectible;
	void		*door_closed;
	void		*door_open;
	void		*idle_1;
	void		*idle_2;
	void		*idle_3;
	void		*idle_4;
	void		*enemy_1;
	void		*enemy_2;
	void		*enemy_3;
	void		*enemy_4;
}	t_windows;

int				get_height(char *file);
int				get_width(t_windows *windows);
int				get_map_size(t_windows *windows, char *file);
int				convert_map_to_array(t_windows *windows, char *file);
void			ft_print_array(t_windows *windows, char **array);
int				check_map_info(char **map, t_windows *windows);
int				map_checker(char **map, t_windows *windows);
int				check_quant(char **map, t_windows *window);
void			texture_drawing(t_windows *windows, int i, int j);
int				check_borders(char **map, t_windows *windows);
int				draw_windows(t_windows *windows);
int				check_line(char **map, int x, int y, t_windows *windows);
int				check_row(char **map, int x, int y, t_windows *windows);
void			free_array(char **array, int y);
int				draw_map(t_windows *windows);
int				handle_render(int keysym, t_windows *data);
int				handle_no_event(void *data);
void			initialize(t_windows *windows);
void			initialize_sprites(t_windows *windows);
void			player_animation(t_windows *windows, int i, int j);
void			change_array(t_windows *windows, int x, int y, char chr);
int				check_move(t_windows *windows, char c);
char			*put_text(char *text, int nbr);
void			end_game(t_windows *windows);
void			enemy_animation(t_windows *windows);
int				check_enemy_move(t_windows *windows, char c);
void 			change_enemies(t_windows *windows, char one, char two);
void    		random_generator(t_windows *windows);
void 			enemy_trigger(t_windows *windows);
void   			enemy_movement(t_windows *windows, int y, int x, char two);
void    		enemy_movement_y(t_windows *windows, int y, int x, char two);
void   			enemy_movement_x(t_windows *windows, int y, int x, char two);
int				changes(t_windows *windows);
void			render_wall(t_windows *windows);
void 			text_to_screen(t_windows *windows);