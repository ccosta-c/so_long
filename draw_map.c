/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/20 15:20:42 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_windows windows, char **map_array)
{
	int	i;
	int	j;
	t_texture	wall;

	i = 0;
	j = 0;
	while(map_array[i][j] != '\0') 
  	{
    	while(map_array[i][j] != '\0')
	  	{
      		if(map_array[i][j] == '1')
				wall.
				wall.xmp_ptr = mlx_xpm_file_to_image(windows->mlx_ptr, )
    	}
    	i++;
    	j = 0;
	}
}