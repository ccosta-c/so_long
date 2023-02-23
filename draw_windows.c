/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:14:21 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 16:57:55 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_windows *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	draw_windows(t_windows *windows)
{	
	windows->mlx_ptr = mlx_init();
	if (windows->mlx_ptr == NULL)
		return (1);
	windows->win_ptr = mlx_new_window(windows->mlx_ptr, (windows->x_size * 32), 
		(windows->y_size * 32), "so_long");
	draw_map(windows);
	initialize(windows);
	mlx_loop_hook(windows->mlx_ptr, &draw_map, &windows);
	mlx_hook(windows->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &windows);
	mlx_loop(windows->mlx_ptr);
	mlx_destroy_display(windows->mlx_ptr);
	free(windows->mlx_ptr);
	return(0);
}