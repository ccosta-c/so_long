/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:39:10 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/20 15:04:21 by ccosta-c         ###   ########.fr       */
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
	void	*mlx_ptr;
    void	*win_ptr;
}	t_windows;


typedef struct s_xpm
{
	void	*xpm_ptr;
    char	*path;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_texture
{
	t_xpm	wall;
	t_xpm	floor;
	t_xpm	coins;
	t_xpm	exit;
	t_xpm	player;
}	t_texture;

int				get_height(char *file);
int 			get_width(char *file);
int				get_map_size(t_coordinates *dimensions, char *file);
char			**convert_map_to_array(t_coordinates dimensions, char *file);
void			ft_print_array (char **array);
int				check_map_info(char **map, t_mapcheck *data);
int				map_checker(char **map, t_mapcheck data, t_coordinates dimensions);
int				check_quant(char **map, t_mapcheck *data);
int				check_borders(char **map, t_coordinates size_map);
int				draw_windows(t_windows *windows, t_coordinates *dimensions, char **map_array);
int				check_line(char **map, int x, int y, t_coordinates size_map);
int				check_row(char **map, int x, int y, t_coordinates size_map);
void			free_array(char **array, int y);