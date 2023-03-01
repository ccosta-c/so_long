/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/27 18:10:55 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_windows *windows)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	enemy_trigger(windows);
	while(i < windows->y_size) 
  	{
    	while(j < windows->x_size)
	  	{
      		texture_drawing(windows, i, j);
			if(windows->render_array[i][j] == 'P')
				player_animation(windows, i, j);
			if(windows->render_array[i][j] == 'I' || windows->render_array[i][j] == 'L')
				enemy_animation(windows, i, j);
			j++;
		}
    	i++;
    	j = 0;
	}
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 32, 0xFFFFFF, put_text("Collectibles Collected: ", windows->collected));
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 20, 0xFFFFFF, put_text("Moves: ", windows->moves));
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