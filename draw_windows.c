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

int	handle_render(int keysym, t_windows *stu)
{
	if (keysym == XK_w || keysym == XK_s)
		handle_render_y(stu, keysym);
	if (keysym == XK_a || keysym == XK_d)
		handle_render_x(stu, keysym);
	if (keysym == XK_Escape)
	{
		ft_printf("GAME CLOSED BY PRESSING ESCAPE!\n");
		end_game(stu);
	}	
	return (0);
}

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
	mlx_hook(stu->win_ptr, KeyPress, KeyPressMask, &handle_render, stu);
	mlx_hook(stu->win_ptr, DestroyNotify, StructureNotifyMask, &end_game, stu);
	mlx_loop_hook(stu->mlx_ptr, &changes, stu);
	mlx_loop(stu->mlx_ptr);
	return (0);
}

void	text_to_screen(t_windows *stu)
{
	stu->str_collectibles = put_text("Collectibles Collected: ",
			stu->collected);
	stu->str_total_collectibles = put_text("/",
			stu->nbr_collectibles);
	stu->str_join_collectibles = ft_strjoin(stu->str_collectibles,
			stu->str_total_collectibles);
	mlx_string_put(stu->mlx_ptr, stu->win_ptr, 10, 32, 0xFFFFFF,
		stu->str_join_collectibles);
	stu->str_moves = put_text("Moves: ", stu->moves);
	mlx_string_put(stu->mlx_ptr, stu->win_ptr, 10, 20, 0xFFFFFF,
		stu->str_moves);
	free(stu->str_total_collectibles);
	free(stu->str_join_collectibles);
	free(stu->str_collectibles);
	free(stu->str_moves);
}

void	handle_render_y(t_windows *stu, int keysym)
{
	if (keysym == XK_w && (check_move(stu,
				stu->render_array[stu->y_player - 1][stu->x_player])))
	{	
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->floor,
			(stu->x_player * 64), (stu->y_player * 64));
		stu->render_array[stu->y_player][stu->x_player] = '0';
		stu->y_player -= 1;
		stu->render_array[stu->y_player][stu->x_player] = 'P';
	}
	if (keysym == XK_s && (check_move(stu,
				stu->render_array[stu->y_player + 1][stu->x_player])))
	{	
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->floor,
			(stu->x_player * 64), (stu->y_player * 64));
		stu->render_array[stu->y_player][stu->x_player] = '0';
		stu->y_player += 1;
		stu->render_array[stu->y_player][stu->x_player] = 'P';
	}
}

void	handle_render_x(t_windows *stu, int keysym)
{
	if (keysym == XK_a && (check_move(stu,
				stu->render_array[stu->y_player][stu->x_player - 1])))
	{	
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->floor,
			(stu->x_player * 64), (stu->y_player * 64));
		stu->render_array[stu->y_player][stu->x_player] = '0';
		stu->x_player -= 1;
		stu->render_array[stu->y_player][stu->x_player] = 'P';
	}
	if (keysym == XK_d && (check_move(stu,
				stu->render_array[stu->y_player][stu->x_player + 1])))
	{	
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->floor,
			(stu->x_player * 64), (stu->y_player * 64));
		stu->render_array[stu->y_player][stu->x_player] = '0';
		stu->x_player += 1;
		stu->render_array[stu->y_player][stu->x_player] = 'P';
	}
}
