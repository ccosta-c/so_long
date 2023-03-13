/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:57:37 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/05 21:58:11 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(char **map, t_windows *stu)
{
	if (check_line(map, 0, 0, stu))
		return (0);
	if (check_row(map, (stu->x_size - 1), 0, stu))
		return (0);
	if (check_line(map, 0, (stu->y_size - 1), stu))
		return (0);
	if (check_row(map, 0, 0, stu))
		return (0);
	return (1);
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
