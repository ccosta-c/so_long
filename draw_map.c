/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 20:47:49 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		draw_map(t_windows *windows)
{
	int		i;
	int		j;
	static int p;
	
	i = 0;
	j = 0;
	while(i < windows->y_size) 
  	{
    	while(j < windows->x_size)
	  	{
      		if(windows->render_array[i][j] == '1')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->wall, (j * 64), (i * 64));
			if(windows->render_array[i][j] == '0')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (j * 64), (i * 64));
			if(windows->render_array[i][j] == 'C')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->collectible, (j * 64), (i * 64));
			if(windows->render_array[i][j] == 'E')
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->door_closed, (j * 64), (i * 64));
			if(windows->render_array[i][j] == 'P')
			{
				player_animation(windows, p, i, j);
				if (p == 300)
					p = 0;
			}
			j++;
		}
    	i++;
    	j = 0;
	}
	
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 16, 32, 0xFFFFFF, ft_itoa(p));
	p++;
	return(0);
}