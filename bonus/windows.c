/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:58:19 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/05 22:07:20 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_windows(t_windows *stu)
{	
	stu->mlx_ptr = mlx_init();
	if (stu->mlx_ptr == NULL)
		return (1);
	stu->win_ptr = mlx_new_window(stu->mlx_ptr, (stu->x_size * 64),
			(stu->y_size * 64), "so_long");
	if (stu->win_ptr == NULL)
	{
		free(stu->win_ptr);
		return (1);
	}
	initialize(stu);
	initialize_sprites(stu);
	draw_map(stu);
	mlx_hook(stu->win_ptr, KeyRelease, KeyReleaseMask, &handle_render, stu);
	mlx_hook(stu->win_ptr, DestroyNotify, StructureNotifyMask, &end_game, stu);
	mlx_loop_hook(stu->mlx_ptr, &changes, stu);
	mlx_loop(stu->mlx_ptr);
	return (0);
}

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

void	initialize(t_windows *stu)
{
	stu->wall = mlx_xpm_file_to_image(stu->mlx_ptr, WALL_PATH,
			&stu->image_width, &stu->image_height);
	stu->floor = mlx_xpm_file_to_image(stu->mlx_ptr, FLOOR_PATH,
			&stu->image_width, &stu->image_height);
	stu->collectible = mlx_xpm_file_to_image(stu->mlx_ptr,
			COLECTIBLE_PATH, &stu->image_width,
			&stu->image_height);
	stu->door_closed = mlx_xpm_file_to_image(stu->mlx_ptr,
			DOOR_CLOSED_PATH, &stu->image_width, &stu->image_height);
	stu->door_open = mlx_xpm_file_to_image(stu->mlx_ptr,
			DOOR_OPEN_PATH, &stu->image_width, &stu->image_height);
}

void	initialize_sprites(t_windows *stu)
{
	stu->idle_1 = mlx_xpm_file_to_image(stu->mlx_ptr, IDLE_1,
			&stu->image_width, &stu->image_height);
	stu->idle_2 = mlx_xpm_file_to_image(stu->mlx_ptr, IDLE_2,
			&stu->image_width, &stu->image_height);
	stu->idle_3 = mlx_xpm_file_to_image(stu->mlx_ptr, IDLE_3,
			&stu->image_width, &stu->image_height);
	stu->idle_4 = mlx_xpm_file_to_image(stu->mlx_ptr, IDLE_4,
			&stu->image_width, &stu->image_height);
	stu->enemy_1 = mlx_xpm_file_to_image(stu->mlx_ptr, ENEMY_1,
			&stu->image_width, &stu->image_height);
	stu->enemy_2 = mlx_xpm_file_to_image(stu->mlx_ptr, ENEMY_2,
			&stu->image_width, &stu->image_height);
	stu->enemy_3 = mlx_xpm_file_to_image(stu->mlx_ptr, ENEMY_3,
			&stu->image_width, &stu->image_height);
	stu->enemy_4 = mlx_xpm_file_to_image(stu->mlx_ptr, ENEMY_4,
			&stu->image_width, &stu->image_height);
}
