/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:16:44 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/16 15:10:36 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	line = "start";
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			i++;
	}
	close(fd);
	return(i);
}

int get_width(char *file)
{
	char	*line;
	int 	reference;
	int		i;
	int		fd;

	i = 0;
	reference = 0;
	line = "start";
	fd = open(file, O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return(i);
		if (reference == 0)
			reference = ft_strlenwithoutn(line);
		i = ft_strlenwithoutn(line);
		if (i != reference)
		{
			ft_printf("Lines width is not equal to all of the lines.\n");
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (i);
}

int		check_borders(char **map, t_coordinates size_map)
{
	if (check_line(map, 0, 0, size_map))
		return (0);
	if (check_row(map, (size_map.x - 1), 0, size_map))
		return (0);	
	if (check_line(map, 0, (size_map.y - 1), size_map))
		return (0);
	if (check_row(map, 0, 0, size_map))
		return (0);	
	return (1);
}

int	get_map_size(t_coordinates *size_map, char *file)
{
	size_map->y = get_height(file);
	size_map->x = get_width(file);
	if (size_map->x == 0)
		return (1);
	ft_printf("Map Height - %d\n", size_map->y);
	ft_printf("Map Width - %d\n", size_map->x);
	ft_printf("--------------------------\n");
	return (0);
}