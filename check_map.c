/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:55:27 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/01 14:14:51 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map, t_windows *stu, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || !map[y][x])
		return ;
	else
	{
		if (map[y][x] == 'C')
			stu->collectibles_found++;
		if (map[y][x] == 'E')
			stu->found_exit++;
		map[y][x] = 'X';
		check_map(map, stu, (x + 1), y);
		check_map(map, stu, (x - 1), y);
		check_map(map, stu, x, (y + 1));
		check_map(map, stu, x, (y - 1));
	}
}

int	map_checker(char **map, t_windows *stu)
{
	if (!(check_borders(map, stu)))
	{
		ft_printf("The map doesen't have valid borders.\n");
		return (0);
	}
	ft_printf("Number of Collectibles - %d\n", stu->nbr_collectibles);
	ft_printf("Player Position X-%d Y-%d\n",
		stu->x_player, stu->y_player);
	if (stu->exits != 1 || stu->players != 1)
	{	
		ft_printf("Map is not valid.\n");
		return (0);
	}
	check_map(map, stu, stu->x_player, stu->y_player);
	if ((stu->collectibles_found != stu->nbr_collectibles)
		|| (stu->found_exit != 1))
	{
		ft_printf("Map is not valid.\n");
		return (0);
	}
	ft_printf("Map is valid!\n");
	return (1);
}

int	check_quant(char **map, t_windows *stu)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < stu->y_size)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != 'C' && map[i][j] != '0' && map[i][j] != 'I')
				return (1);
			check_char_map(stu, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	check_map_info(char **map, t_windows *stu)
{
	stu->nbr_collectibles = 0;
	stu->collectibles_found = 0;
	stu->players = 0;
	stu->found_exit = 0;
	stu->exits = 0;
	if (check_quant(map, stu))
	{
		ft_printf("Invalid characters in the file.");
		return (1);
	}
	if (stu->nbr_collectibles < 1)
	{
		ft_printf("There's no collectibles in the map.");
		return (1);
	}
	return (0);
}

void	check_char_map(t_windows *stu, int i, int j)
{
	if (stu->render_array[i][j] == 'C')
		stu->nbr_collectibles++;
	if (stu->render_array[i][j] == 'P')
	{
		if (stu->players == 0)
		{
			stu->x_player = j;
			stu->y_player = i;
		}
		stu->players++;
	}
	if (stu->render_array[i][j] == 'E')
	{
		stu->exits++;
		stu->x_exit = j;
		stu->y_exit = i;
	}
}
