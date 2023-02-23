/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 16:53:48 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		draw_map(t_windows *windows)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(i < windows->y_size) 
  	{
    	while(j < windows->x_size)
	  	{
      		if(windows->render_array[i][j] == '1')
			{
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->wall, (j * 32), (i * 32));
			}
			if(windows->render_array[i][j] == '0')
			{
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (j * 32), (i * 32));
			}
			if(windows->render_array[i][j] == 'C')
			{
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->collectible, (j * 32), (i * 32));
			}
			if(windows->render_array[i][j] == 'E')
			{
				mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->door_closed, (j * 32), (i * 32));
			}
			j++;
		}
    	i++;
    	j = 0;
	}
	return(0);
}