/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:18:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 20:47:45 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_windows *windows, int x, int i, int j)
{
	if (x == 0)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_1, (j * 64), (i * 64));
	if (x == 100)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_2, (j * 64), (i * 64));
	if (x == 200)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_3, (j * 64), (i * 64));
	if (x == 300)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_4, (j * 64), (i * 64));
}

int	check_line(char **map, int x, int y, t_windows windows)
{
	while(x < windows.x_size)
	{
		if (map[y][x] != '1')
			return(1);
		x++;
	}
	return (0);
}

int	check_row(char **map, int x, int y, t_windows windows)
{
	while(y < windows.y_size)
	{
		if (map[y][x] != '1')
			return(1);
		y++;
	}
	return (0);
}