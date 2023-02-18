/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:14:21 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/16 15:13:40 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_windows(t_data *windows, t_coordinates *dimensions)
{	
	windows->mlx_ptr = mlx_init();
	if (windows->mlx_ptr == NULL)
		return (1);
	windows->win_ptr = mlx_new_window(windows->mlx_ptr, (dimensions->x * 32), 
		(dimensions->y * 32), "so_long");
	mlx_loop(windows->mlx_ptr);
	mlx_destroy_window(windows->mlx_ptr, windows->win_ptr);
	mlx_destroy_display(windows->mlx_ptr);
	free(windows->mlx_ptr);
	return(0);
}