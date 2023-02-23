/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:38:55 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 16:46:18 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_windows *windows)
{
	windows->wall = mlx_xpm_file_to_image(windows->mlx_ptr, WALL_PATH, &windows->wall_width, &windows->wall_height);
	windows->floor = mlx_xpm_file_to_image(windows->mlx_ptr, FLOOR_PATH, &windows->floor_width, &windows->floor_height);
	windows->collectible = mlx_xpm_file_to_image(windows->mlx_ptr, COLECTIBLE_PATH, &windows->collectible_width, &windows->collectible_height);
	windows->door_closed = mlx_xpm_file_to_image(windows->mlx_ptr, DOOR_CLOSED_PATH, &windows->dc_width, &windows->dc_height);
	windows->idle_1 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_1, &windows->idle_1_width, &windows->idle_1_height);
	windows->idle_2 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_2, &windows->idle_2_width, &windows->idle_2_height);
	windows->idle_3 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_3, &windows->idle_3_width, &windows->idle_3_height);
	windows->idle_4 = mlx_xpm_file_to_image(windows->mlx_ptr, IDLE_4, &windows->idle_4_width, &windows->idle_4_height);
}

int	main(int argc, char **argv)
{
	t_windows 		windows;
	t_mapcheck 		map_data;
	char 			**map_array;

	if (argc != 2)
		return(0);
	if (get_map_size(&windows, argv[1]))
		return (1);
	map_array = convert_map_to_array(windows, argv[1]);
	ft_printf("The 2D Map Array Generated\n");
	ft_print_array(map_array);
	ft_printf("--------------------------\n");
	if (check_map_info(map_array, &map_data))
	{
		return (1);
	}
	if (!(map_checker(map_array, map_data, windows)))
		return (0);
	free_array(map_array, windows.y_size);
	windows.render_array = convert_map_to_array(windows, argv[1]);
	draw_windows(&windows);
	free_array(windows.render_array, windows.y_size);
	return(0);
}