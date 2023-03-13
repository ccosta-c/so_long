/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:32:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/05 21:52:54 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	changes(t_windows *stu)
{
	static int	i;

	if (i == 5000)
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
	if (x == 1000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_2, (j * 64), (i * 64));
	if (x == 2000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_3, (j * 64), (i * 64));
	if (x == 3000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_4, (j * 64), (i * 64));
	if (x == 3000)
		x = 0;
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

	if (q < 1000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_1, (x * 64), (y * 64));
	if (q >= 1000 && q < 2000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_2, (x * 64), (y * 64));
	if (q >= 2000 && q < 3000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_3, (x * 64), (y * 64));
	if (q >= 3000 && q <= 4000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->enemy_4, (x * 64), (y * 64));
	if (q == 4000)
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