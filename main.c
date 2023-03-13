/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:31:07 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/06 15:39:59 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_windows	stu;

	if (argc != 2)
	{
		ft_printf("\033[1;31mERROR! Please specify a map.\033[0m\n");
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
