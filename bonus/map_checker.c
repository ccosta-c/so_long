/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:44:11 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/26 18:58:07 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char **map, t_windows *stu)
{
	if (!(check_borders(map, stu)))
	{
		ft_printf("\033[1;31mERROR!\nInvalid borders.\033[0m\n");
		return (0);
	}
	if (stu->exits != 1 || stu->players != 1)
	{	
		ft_printf("\033[1;31mERROR!\nWrong number of players/exits.\033[0m\n");
		return (0);
	}
	check_map(map, stu, stu->x_player, stu->y_player);
	if (stu->found_exit != 1)
	{
		ft_printf("\033[1;31mERROR!\nCan't reach the exit.\033[0m\n");
		return (0);
	}
	if (stu->collectibles_found != stu->nbr_collectibles)
	{
		ft_printf("\033[1;31mERROR!\nCan't reach all collectibles.\033[0m\n");
		return (0);
	}
	ft_printf("The map is valid!\n");
	return (1);
}

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

int	check_map_info(char **map, t_windows *stu)
{
	stu->nbr_collectibles = 0;
	stu->collectibles_found = 0;
	stu->players = 0;
	stu->found_exit = 0;
	stu->exits = 0;
	if (check_quant(map, stu))
	{
		ft_printf("\033[1;31mERROR!\nInvalid characters.\033[0m\n");
		return (1);
	}
	if (stu->nbr_collectibles < 1)
	{
		ft_printf("\033[1;31mERROR!\nNo collectibles.\033[0m\n");
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
		stu->x_player = j;
		stu->y_player = i;
		stu->players++;
	}
	if (stu->render_array[i][j] == 'E')
	{
		stu->exits++;
		stu->x_exit = j;
		stu->y_exit = i;
	}
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
