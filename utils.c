/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:18:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/03 12:18:21 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_windows *stu)
{
	mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->wall,
		(0 * 64), (0 * 64));
	mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->wall,
		(1 * 64), (0 * 64));
	mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr, stu->wall,
		(2 * 64), (0 * 64));
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
		ft_printf("CONGRATULATIONS!!! YOU MADE IT TO THE EXIT!\n");
		end_game(stu);
	}
	if (c == 'I' || c == 'L')
	{
		ft_printf("YOU GOT HIT BY AN ENEMY! GAME OVER!\n");
		end_game(stu);
	}
	stu->moves += 1;
	return (1);
}

char	*put_text(char *text, int nbr)
{
	char	*nbr_str;
	char	*str;

	nbr_str = ft_itoa(nbr);
	str = ft_strjoin(text, nbr_str);
	free(nbr_str);
	return (str);
}

void	player_animation(t_windows *stu, int i, int j)
{
	static int	x;	

	if (x == 0)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_1, (j * 64), (i * 64));
	if (x == 1000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_2, (j * 64), (i * 64));
	if (x == 2000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_3, (j * 64), (i * 64));
	if (x == 3000)
		mlx_put_image_to_window(stu->mlx_ptr, stu->win_ptr,
			stu->idle_4, (j * 64), (i * 64));
	if (x == 3000)
		x = 0;
	x++;
}

int	check_line(char **map, int x, int y, t_windows *stu)
{
	while (x < stu->x_size)
	{
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_row(char **map, int x, int y, t_windows *stu)
{
	while (y < stu->y_size)
	{
		if (map[y][x] != '1')
			return (1);
		y++;
	}
	return (0);
}
