/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:38:55 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/20 14:48:59 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_coordinates 	dimensions;
	t_windows 			windows;
	t_mapcheck 		map_data;
	char 			**map_array;

	if (argc != 2)
		return(0);
	if (get_map_size(&dimensions, argv[1]))
		return (1);
	map_array = convert_map_to_array(dimensions, argv[1]);
	ft_printf("The 2D Map Array Generated\n");
	ft_print_array(map_array);
	ft_printf("--------------------------\n");
	if (check_map_info(map_array, &map_data))
	{
		return (1);
	}
	if (!(map_checker(map_array, map_data, dimensions)))
		return (0);
	free_array(map_array, dimensions.y);
	map_array = convert_map_to_array(dimensions, argv[1]);
	ft_print_array(map_array);
	draw_windows(&windows, &dimensions, map_array);
	return(0);
}