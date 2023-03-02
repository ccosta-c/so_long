/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:18:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/02 17:09:30 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_move(t_windows *windows, char c)
{
	if (c == '1')
		return (0);
	if (c == 'C')
	{
		windows->collected += 1;
		if (windows->nbr_collectibles == windows->collected)
			windows->render_array[windows->y_exit][windows->x_exit] = 'S';
	}
	if (c == 'E')
		return (0);
	if (c == 'S')
	{
		ft_printf("CONGRATULATIONS!!! YOU MADE IT TO THE EXIT!\n");
		end_game(windows);
	}
	if (c == 'I' || c == 'L')
	{
		ft_printf("YOU GOT HIT BY AN ENEMY! GAME OVER!\n");
		end_game(windows);
	}
	windows->moves += 1;
	return (1);
}

char	*put_text(char *text, int nbr)
{
	char	*nbr_str;
	char	*str;

	nbr_str = ft_itoa(nbr);
	str = ft_strjoin(text, nbr_str);
	return (str);
}

void	player_animation(t_windows *windows, int i, int j)
{
	static int	x;	
	
	if (x == 0)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_1, (j * 64), (i * 64));
	if (x == 100)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_2, (j * 64), (i * 64));
	if (x == 200)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_3, (j * 64), (i * 64));
	if (x == 300)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->idle_4, (j * 64), (i * 64));
	if (x == 300)
		x = 0;
	x++;
}

int	check_line(char **map, int x, int y, t_windows *windows)
{
	while(x < windows->x_size)
	{
		if (map[y][x] != '1')
			return(1);
		x++;
	}
	return (0);
}

int	check_row(char **map, int x, int y, t_windows *windows)
{
	while(y < windows->y_size)
	{
		if (map[y][x] != '1')
			return(1);
		y++;
	}
	return (0);
}