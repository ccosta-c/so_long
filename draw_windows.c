/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:14:21 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/03 12:15:09 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_render(int keysym, t_windows *windows)
{
	if (keysym == XK_w && (check_move(windows, windows->render_array[windows->y_player - 1][windows->x_player])))
	{	
			mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (windows->x_player * 64), (windows->y_player * 64));
			windows->render_array[windows->y_player][windows->x_player] = '0';
			windows->y_player -= 1;
			windows->render_array[windows->y_player][windows->x_player] = 'P';
			return (0);
	}
	if (keysym == XK_s && (check_move(windows, windows->render_array[windows->y_player + 1][windows->x_player])))
	{	
			mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (windows->x_player * 64), (windows->y_player * 64));
			windows->render_array[windows->y_player][windows->x_player] = '0';
			windows->y_player += 1;
			windows->render_array[windows->y_player][windows->x_player] = 'P';
			return (0);
	}
	if (keysym == XK_a && (check_move(windows, windows->render_array[windows->y_player][windows->x_player - 1])))
	{	
			mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (windows->x_player * 64), (windows->y_player * 64));
			windows->render_array[windows->y_player][windows->x_player] = '0';
			windows->x_player -= 1;
			windows->render_array[windows->y_player][windows->x_player] = 'P';
			return (0);
	}
	if (keysym == XK_d && (check_move(windows, windows->render_array[windows->y_player][windows->x_player + 1])))
	{	
			mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (windows->x_player * 64), (windows->y_player * 64));
			windows->render_array[windows->y_player][windows->x_player] = '0';
			windows->x_player += 1;
			windows->render_array[windows->y_player][windows->x_player] = 'P';
			return (0);
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
	initialize_sprites(windows);
	draw_map(windows);
	mlx_hook(windows->win_ptr, KeyPress, KeyPressMask, &handle_render, windows);
	mlx_loop_hook(windows->mlx_ptr, &changes, windows);
	mlx_loop(windows->mlx_ptr);
	return(0);
}

void text_to_screen(t_windows *windows)
{
	windows->str_collectibles = put_text("Collectibles Collected: ", windows->collected);
	windows->str_total_collectibles = put_text("/", windows->nbr_collectibles);
	windows->str_join_collectibles = ft_strjoin(windows->str_collectibles, windows->str_total_collectibles);
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 32, 0xFFFFFF, windows->str_join_collectibles);
	windows->str_moves = put_text("Moves: ", windows->moves);
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 20, 0xFFFFFF, windows->str_moves);
	free(windows->str_total_collectibles);
	free(windows->str_join_collectibles);
	free(windows->str_collectibles);
	free(windows->str_moves);
}