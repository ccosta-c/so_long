/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:34:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/06 15:55:08 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_trigger(t_windows *stu)
{
	static int	e;

	if (e % 2 == 0)
		change_enemies(stu, 'I', 'L');
	if (e % 2 != 0)
		change_enemies(stu, 'L', 'I');
	e++;
}

void	change_enemies(t_windows *stu, char one, char two)
{
	int	x;
	int	y;

	y = -1;
	while (++y < stu->y_size)
	{
		x = -1;
		while (++x < stu->x_size)
		{
			if (stu->render_array[y][x] == one)
			{
				random_generator(stu);
				if (stu->rand == 1)
					enemy_movement_y(stu, y, x, two);
				if (stu->rand == 2)
					enemy_movement_y(stu, y, x, two);
				if (stu->rand == 3)
					enemy_movement_x(stu, y, x, two);
				if (stu->rand == 4)
					enemy_movement_x(stu, y, x, two);
			}
		}
	}
}

void	enemy_movement_y(t_windows *stu, int y, int x, char two)
{
	if (stu->rand == 1)
	{
		if (check_enemy_move(stu, stu->render_array[y - 1][x]))
		{
			stu->render_array[y][x] = '0';
			mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
				stu->floor, (x * 64), (y * 64));
			stu->render_array[y - 1][x] = two;
		}
	}
	if (stu->rand == 2)
	{
		if (check_enemy_move(stu, stu->render_array[y + 1][x]))
		{
			stu->render_array[y][x] = '0';
			mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
				stu->floor, (x * 64), (y * 64));
			stu->render_array[y + 1][x] = two;
		}
	}
}

void	enemy_movement_x(t_windows *stu, int y, int x, char two)
{
	if (stu->rand == 3)
	{
		if (check_enemy_move(stu, stu->render_array[y][x - 1]))
		{
			stu->render_array[y][x] = '0';
			mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
				stu->floor, (x * 64), (y * 64));
			stu->render_array[y][x - 1] = two;
		}
	}
	if (stu->rand == 4)
	{
		if (check_enemy_move(stu, stu->render_array[y][x + 1]))
		{
			stu->render_array[y][x] = '0';
			mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
				stu->floor, (x * 64), (y * 64));
			stu->render_array[y][x + 1] = two;
		}
	}
}

int	check_enemy_move(t_windows *stu, char c)
{
	if (c == '1' || c == 'C' || c == 'E' || c == 'S')
		return (0);
	if (c == 'I' || c == 'L')
		return (0);
	if (c == 'P')
	{
		ft_printf("\033[1;31m💀GAME OVER!!! AN ENEMY HIT YOU!💀\033[0m\n");
		end_game(stu);
	}
	return (1);
}
