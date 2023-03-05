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

int	end_game(t_windows *stu)
{	
	mlx_destroy_image(stu->mlx_ptr, stu->wall);
	mlx_destroy_image(stu->mlx_ptr, stu->floor);
	mlx_destroy_image(stu->mlx_ptr, stu->collectible);
	mlx_destroy_image(stu->mlx_ptr, stu->door_closed);
	mlx_destroy_image(stu->mlx_ptr, stu->door_open);
	mlx_destroy_image(stu->mlx_ptr, stu->idle_1);
	mlx_destroy_image(stu->mlx_ptr, stu->idle_2);
	mlx_destroy_image(stu->mlx_ptr, stu->idle_3);
	mlx_destroy_image(stu->mlx_ptr, stu->idle_4);
	mlx_destroy_image(stu->mlx_ptr, stu->enemy_1);
	mlx_destroy_image(stu->mlx_ptr, stu->enemy_2);
	mlx_destroy_image(stu->mlx_ptr, stu->enemy_3);
	mlx_destroy_image(stu->mlx_ptr, stu->enemy_4);
	mlx_destroy_window(stu->mlx_ptr, stu->win_ptr);
	mlx_destroy_display(stu->mlx_ptr);
	free_array(stu->render_array, stu->y_size);
	free(stu->mlx_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_windows	stu;

	if (argc != 2)
	{
		ft_printf("Please specify the map.\n");
		return (1);
	}
	if (get_map_size(&stu, argv[1]))
		return (1);
	ft_printf("The 2D Map Array Generated\n");
	ft_print_array(&stu, stu.render_array);
	ft_printf("--------------------------\n");
	if (check_map_info(stu.render_array, &stu))
		return (1);
	if (!(map_checker(stu.render_array, &stu)))
		return (0);
	stu.collected = 0;
	stu.moves = 0;
	free_array(stu.render_array, stu.y_size);
	convert_map_to_array(&stu, argv[1]);
	draw_windows(&stu);
	return (0);
}
