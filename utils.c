/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:18:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 15:45:58 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char **map, int x, int y, t_windows windows)
{
	while(x < windows.x_size)
	{
		if (map[y][x] != '1')
			return(1);
		x++;
	}
	return (0);
}

int	check_row(char **map, int x, int y, t_windows windows)
{
	while(y < windows.y_size)
	{
		if (map[y][x] != '1')
			return(1);
		y++;
	}
	return (0);
}