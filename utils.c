/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:18:25 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/16 15:04:05 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char **map, int x, int y, t_coordinates size_map)
{
	while(x < size_map.x)
	{
		if (map[y][x] != '1')
			return(1);
		x++;
	}
	return (0);
}

int	check_row(char **map, int x, int y, t_coordinates size_map)
{
	while(y < size_map.y)
	{
		if (map[y][x] != '1')
			return(1);
		y++;
	}
	return (0);
}