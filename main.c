/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:38:55 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/01 11:54:57 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_windows *windows)
{
	windows->wall = mlx_xpm_file_to_image(windows->mlx_ptr, WALL_PATH, 
		&windows->image_width, &windows->image_height);
	windows->floor = mlx_xpm_file_to_image(windows->mlx_ptr, FLOOR_PATH, 
		&windows->image_width, &windows->image_height);
	windows->collectible = mlx_xpm_file_to_image(windows->mlx_ptr, 
		COLECTIBLE_PATH, &windows->image_width, 
		&windows->image_height);
	windows->door_closed = mlx_xpm_file_to_image(windows->mlx_ptr, 
		DOOR_CLOSED_PATH, &windows->image_width, &windows->image_height);
	windows->door_open = mlx_xpm_file_to_image(windows->mlx_ptr, 
		DOOR_OPEN_PATH, &windows->image_width, &windows->image_height);
}

void	initialize_sprites(t_windows *windows)
{
	windows->idle_1 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_1, 
		&windows->image_width, &windows->image_height);
	windows->idle_2 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_2, 
		&windows->image_width, &windows->image_height);
	windows->idle_3 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_3, 
		&windows->image_width, &windows->image_height);
	windows->idle_4 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_4, 
		&windows->image_width, &windows->image_height);
	windows->enemy_1 = mlx_xpm_file_to_image(windows->mlx_ptr, ENEMY_1, 
		&windows->image_width, &windows->image_height);
	windows->enemy_2 = mlx_xpm_file_to_image(windows->mlx_ptr, ENEMY_2, 
		&windows->image_width, &windows->image_height);
	windows->enemy_3 = mlx_xpm_file_to_image(windows->mlx_ptr, ENEMY_3, 
		&windows->image_width, &windows->image_height);
	windows->enemy_4 = mlx_xpm_file_to_image(windows->mlx_ptr, ENEMY_4, 
		&windows->image_width, &windows->image_height);
}

void	end_game(t_windows *windows)
{	
	mlx_destroy_image(windows->mlx_ptr, windows->wall);
	mlx_destroy_image(windows->mlx_ptr, windows->floor);
	mlx_destroy_image(windows->mlx_ptr, windows->collectible);
	mlx_destroy_image(windows->mlx_ptr, windows->door_closed);
	mlx_destroy_image(windows->mlx_ptr, windows->door_open);	
	mlx_destroy_image(windows->mlx_ptr, windows->idle_1);
	mlx_destroy_image(windows->mlx_ptr, windows->idle_2);
	mlx_destroy_image(windows->mlx_ptr, windows->idle_3);
	mlx_destroy_image(windows->mlx_ptr, windows->idle_4);
	mlx_destroy_image(windows->mlx_ptr, windows->enemy_1);
	mlx_destroy_image(windows->mlx_ptr, windows->enemy_2);
	mlx_destroy_image(windows->mlx_ptr, windows->enemy_3);
	mlx_destroy_image(windows->mlx_ptr, windows->enemy_4);
	mlx_destroy_window(windows->mlx_ptr, windows->win_ptr);
	mlx_destroy_display(windows->mlx_ptr);
	free_array(windows->render_array, windows->y_size);
	free(windows->mlx_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_windows 		windows;

	if (argc != 2)
	{
		ft_printf("Please specify the map.\n");
		return(1);
	}
	if (get_map_size(&windows, argv[1]))
		return (1);
	ft_printf("The 2D Map Array Generated\n");
	ft_print_array(&windows, windows.render_array);
	ft_printf("--------------------------\n");
	if (check_map_info(windows.render_array, &windows))
		return (1);
	if (!(map_checker(windows.render_array, &windows)))
		return (0);
	windows.collected = 0;
	windows.moves = 0;
	free_array(windows.render_array, windows.y_size);
	convert_map_to_array(&windows, argv[1]);
	draw_windows(&windows);
	return(0);
}