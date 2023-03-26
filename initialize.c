/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:32:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/26 18:57:16 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	changes(t_windows *stu)
{
	player_animation(stu, stu->y_player, stu->x_player);
	render_wall(stu);
	text_to_screen(stu);
	return (0);
}

void	player_animation(t_windows *stu, int i, int j)
{
	static int	x;	

	if (x == 0)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_1, (j * 64), (i * 64));
	if (x == 1500)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_2, (j * 64), (i * 64));
	if (x == 3000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_3, (j * 64), (i * 64));
	if (x == 4500)
	{
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_4, (j * 64), (i * 64));
		x = 0;
	}
	x++;
}

void	render_wall(t_windows *stu)
{
	mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->wall,
		(0 * 64), (0 * 64));
	mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->wall,
		(1 * 64), (0 * 64));
	mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->wall,
		(2 * 64), (0 * 64));
}
