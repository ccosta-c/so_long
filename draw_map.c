/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/01 12:30:01 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_windows *windows)
{
	int		i;
	int		j;
	
	i = -1;
	usleep(500);
	enemy_trigger(windows);
	while(++i < windows->y_size) 
  	{
    	j = -1;
		while(++j < windows->x_size)
	  	{
      		texture_drawing(windows, i, j);
			if(windows->render_array[i][j] == 'P')
				player_animation(windows, i, j);
			if(windows->render_array[i][j] == 'I' || windows->render_array[i][j] == 'L')
				enemy_animation(windows, i, j);
		} 	
	}
	windows->str_collectibles = put_text("Collectibles Collected: ", windows->collected);
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 32, 0xFFFFFF, windows->str_collectibles);
	windows->str_moves = put_text("Moves: ", windows->moves);
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 20, 0xFFFFFF, windows->str_moves);
	free(windows->str_collectibles);
	free(windows->str_moves);
	return (0);
}

void	texture_drawing(t_windows *windows, int i, int j)
{
	if(windows->render_array[i][j] == '1')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->wall, (j * 64), (i * 64));
			if(windows->render_array[i][j] == '0')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (j * 64), (i * 64));
			if(windows->render_array[i][j] == 'C')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->collectible, (j * 64), (i * 64));
			if(windows->render_array[i][j] == 'E')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->door_closed, (j * 64), (i * 64));
			if(windows->render_array[i][j] == 'S')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->door_open, (j * 64), (i * 64));
}