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

void	check_map(char **map, t_windows *windows, int x, int y)
{

	if(map[y][x] == '1' || map[y][x] == 'X' || !map[y][x])
		return ;
	else
	{
		if (map[y][x] == 'C')
			windows->collectibles_found++;
		if (map[y][x] == 'E')
			windows->found_exit++;
		map[y][x] = 'X';
		check_map(map, windows, (x + 1), y);
		check_map(map, windows, (x - 1), y);
		check_map(map, windows, x, (y + 1));
		check_map(map, windows, x, (y - 1));
	}
}

int	map_checker(char **map, t_windows *windows)
{
	if(!(check_borders(map, windows)))
	{
		ft_printf("The map doesen't have valid borders.\n");
		return (0);
	}
	ft_printf("Number of Collectibles - %d\n", windows->nbr_collectibles);
  	ft_printf("Player Position X-%d Y-%d\n", windows->x_player, windows->y_player);
	if(windows->exits != 1 || windows->players != 1)
	{	
		ft_printf("Map is not valid.\n");
		return (0);
	}
	check_map(map, windows, windows->x_player, windows->y_player);
	if((windows->collectibles_found != windows->nbr_collectibles) || (windows->found_exit != 1))
	{
		ft_printf("Map is not valid.\n");
		return (0);
	}
	ft_printf("Map is valid!\n");
	return (1);
}

int	check_quant(char **map, t_windows *windows)
{
	int			i;
	int			j;

	i = 0;
  	j = 0;
	while(i < windows->y_size) 
	{
    	while(map[i][j] != '\0')
		{
			if(map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '0' && map[i][j] != 'I')
				return (1);
			if(map[i][j] == 'C')
				windows->nbr_collectibles++;
			if(map[i][j] == 'P')
			{
				if (windows->players == 0)
				{
					windows->x_player = j;
					windows->y_player = i;
				}
				windows->players++;
			}
			if (map[i][j] == 'E')
			{
				windows->exits++;
				windows->x_exit = j;
				windows->y_exit = i;
			}
			j++;
		}
    	i++;
    	j = 0;
  	}
	return (0);
}

int	check_map_info(char **map, t_windows *windows)
{
	windows->nbr_collectibles = 0;
	windows->collectibles_found = 0;
	windows->players = 0;
	windows->found_exit = 0;
	windows->exits = 0;
	if(check_quant(map, windows))
	{
		ft_printf("Invalid characters in the file.");
		return (1);
	}
	if(windows->nbr_collectibles < 1)
	{
		ft_printf("There's no collectibles in the map.");
		return (1);
	}
  return (0);
}