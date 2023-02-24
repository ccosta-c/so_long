/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:14:21 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/24 20:23:17 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_render(int keysym, t_windows *windows)
{
	if (keysym == XK_w)
	{	
		if (check_move(windows, windows->render_array[windows->y_player - 1][windows->x_player]))
			return (0);
		windows->render_array[windows->y_player][windows->x_player] = '0';
		windows->y_player -= 1;
		windows->render_array[windows->y_player][windows->x_player] = 'P';
	}
	if (keysym == XK_s)
	{	
		if (check_move(windows, windows->render_array[windows->y_player + 1][windows->x_player]))
			return (0);
		windows->render_array[windows->y_player][windows->x_player] = '0';
		windows->y_player += 1;
		windows->render_array[windows->y_player][windows->x_player] = 'P';
	}
	if (keysym == XK_a)
	{	
		if (check_move(windows, windows->render_array[windows->y_player][windows->x_player - 1]))
			return (0);
		windows->render_array[windows->y_player][windows->x_player] = '0';
		windows->x_player -= 1;
		windows->render_array[windows->y_player][windows->x_player] = 'P';
	}
	if (keysym == XK_d)
	{	
		if (check_move(windows, windows->render_array[windows->y_player][windows->x_player + 1]))
			return (0);
		windows->render_array[windows->y_player][windows->x_player] = '0';
		windows->x_player += 1;
		windows->render_array[windows->y_player][windows->x_player] = 'P';
	}
	if (keysym == XK_Escape)
	{
		ft_printf("GAME CLOSED BY PRESSING ESCAPE!\n");
		end_game(windows);
	}	
	return (0);
}

int	draw_windows(t_windows *windows)
{	
	windows->mlx_ptr = mlx_init();
	if (windows->mlx_ptr == NULL)
		return (1);
	windows->win_ptr = mlx_new_window(windows->mlx_ptr, (windows->x_size * 64), 
		(windows->y_size * 64), "so_long");
	if (windows->win_ptr == NULL)
	{
		free(windows->win_ptr);
		return (1);
	}
	initialize(windows);
	mlx_hook(windows->win_ptr, KeyPress, KeyPressMask, &handle_render, windows);
	mlx_loop_hook(windows->mlx_ptr, &draw_map, windows);
	mlx_loop(windows->mlx_ptr);
	return(0);
}