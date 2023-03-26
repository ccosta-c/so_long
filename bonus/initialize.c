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
	static int	i;

	if (i == 2000)
	{
		enemy_trigger(stu);
		i = 0;
	}
	player_animation(stu, stu->y_player, stu->x_player);
	enemy_animation(stu);
	render_wall(stu);
	text_to_screen(stu);
	i++;
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

void	enemy_animation(t_windows *stu)
{
	int				x;
	int				y;

	y = -1;
	while (++y < stu->y_size)
	{
		x = -1;
		while (++x < stu->x_size)
		{
			if (stu->render_array[y][x] == 'I'
				|| stu->render_array[y][x] == 'L')
			{
				sprite_enemies(stu, y, x);
			}
		}
	}
}

void	sprite_enemies(t_windows *stu, int y, int x)
{
	static int	q;

	if (q < 3000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_1, (x * 64), (y * 64));
	if (q >= 3000 && q < 6000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_2, (x * 64), (y * 64));
	if (q >= 6000 && q < 9000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_3, (x * 64), (y * 64));
	if (q >= 9000 && q <= 12000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_4, (x * 64), (y * 64));
	if (q == 12000)
		q = 0;
	q++;
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
