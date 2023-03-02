/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/02 17:14:21 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_windows *windows)
{
	int		i;
	int		j;
	
	i = -1;
	while(++i < windows->y_size) 
  	{
    	j = -1;
		while(++j < windows->x_size)
	  	{
      		texture_drawing(windows, i, j);
		} 	
	}
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
			if(windows->render_array[i][j] == 'I')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_1, (j * 64), (i * 64));
}