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

int	draw_map(t_windows *stu)
{
	int		i;
	int		j;

	i = -1;
	while (++i < stu->y_size)
	{
		j = -1;
		while (++j < stu->x_size)
		{
			texture_drawing(stu, i, j);
		}
	}
	return (0);
}

void	texture_drawing(t_windows *stu, int i, int j)
{
	if (stu->render_array[i][j] == '1')
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->wall, (j * 64), (i * 64));
	if (stu->render_array[i][j] == '0')
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->floor, (j * 64), (i * 64));
	if (stu->render_array[i][j] == 'C')
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->collectible, (j * 64), (i * 64));
	if (stu->render_array[i][j] == 'E')
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->door_closed, (j * 64), (i * 64));
	if (stu->render_array[i][j] == 'S')
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->door_open, (j * 64), (i * 64));
	if (stu->render_array[i][j] == 'I')
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_1, (j * 64), (i * 64));
}
