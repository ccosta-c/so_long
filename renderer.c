/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:45:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/06 15:54:28 by ccosta-c         ###   ########.fr       */
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
		ft_printf("\033[1;31mGAME CLOSED BY ESCAPE!\033[0m\n");
		end_game(stu);
	}
	return (0);
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

int	check_move(t_windows *stu, char c)
{
	if (c == 'C')
	{
		stu->collected += 1;
		if (stu->nbr_collectibles == stu->collected)
		{
			mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
				stu->door_open, (stu->x_exit * 64), (stu->y_exit * 64));
			stu->render_array[stu->y_exit][stu->x_exit] = 'S';
		}
	}
	if (c == 'E' || c == '1')
		return (0);
	if (c == 'S')
	{
		ft_printf("\033[1;32m✨CONGRATULATIONS! YOU MADE IT TO THE EXIT!✨\033[0m\n");
		end_game(stu);
	}
	if (c == 'I' || c == 'L')
	{
		ft_printf("\033[1;31m💀GAME OVER! YOU GOT HIT BY AN ENEMY!💀\033[0m\n");
		end_game(stu);
	}
	stu->moves += 1;
	return (1);
}