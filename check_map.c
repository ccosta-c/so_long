/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:55:27 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/20 14:36:02 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map, t_mapcheck *data, int x, int y)
{

	if(map[y][x] == '1' || map[y][x] == 'X' || !map[y][x])
		return ;
	else
	{
		if (map[y][x] == 'C')
			data->collectibles_found++;
		if (map[y][x] == 'E')
			data->found_exit++;
		map[y][x] = 'X';
		check_map(map, data, (x + 1), y);
		check_map(map, data, (x - 1), y);
		check_map(map, data, x, (y + 1));
		check_map(map, data, x, (y - 1));
	}
}

int	map_checker(char **map, t_mapcheck data, t_coordinates dimensions)
{
	if(!(check_borders(map, dimensions)))
	{
		ft_printf("The map doesen't have valid borders.\n");
		return (0);
	}
	ft_printf("Number of Collectibles - %d\n", data.collectibles);
  	ft_printf("Player Position X-%d Y-%d\n", data.x, data.y);
	if(data.exits != 1 || data.players != 1)
	{	
		ft_printf("Map is not valid.\n");
		return (0);
	}
	check_map(map, &data, data.x, data.y);
	if((data.collectibles_found != data.collectibles) || (data.found_exit != 1))
	{
		ft_printf("Map is not valid.\n");
		return (0);
	}
	ft_printf("Map is valid!\n");
	return (1);
}

int	check_quant(char **map, t_mapcheck *data)
{
	int			i;
	int			j;

	i = 0;
  	j = 0;
	while(map[i][j] != '\0') 
	{
    	while(map[i][j] != '\0')
		{
			if(map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '0')
				return (1);
			if(map[i][j] == 'C')
				data->collectibles++;
			if(map[i][j] == 'P')
			{
				if (data->players == 0)
				{
					data->x = j;
					data->y = i;
				}
				data->players++;
			}
			if (map[i][j] == 'E')
				data->exits++;
			j++;
		}
    	i++;
    	j = 0;
  	}
	return (0);
}

int	check_map_info(char **map, t_mapcheck *data)
{
	data->collectibles = 0;
	data->collectibles_found = 0;
	data->players = 0;
	data->found_exit = 0;
	data->exits = 0;
	if(check_quant(map, data))
	{
		ft_printf("Invalid characters in the file.");
		return (1);
	}
	if(data->collectibles < 1)
	{
		ft_printf("There's no collectibles in the map.");
		return (1);
	}
  return (0);
}