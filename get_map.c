/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:26:28 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/16 11:14:17 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**convert_map_to_array(t_coordinates dimensions, char *file)
{
	char 	**map_array;
	int		fd;
	char	*line;
	t_coordinates xandy;
	
	fd = open(file, O_RDONLY);
	line = "start";
	xandy.x = 0;
	xandy.y = 0; 
	map_array = (char **)malloc((dimensions.y + 1) * sizeof(char*));
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			map_array[xandy.y] = (char *)malloc((dimensions.x + 1) * sizeof(char));
		while (line && line[xandy.x] != '\0' && line[xandy.x] != '\n')
		{
			map_array[xandy.y][xandy.x] = line[xandy.x];
			xandy.x++;
		}
		if (line)
		{
			map_array[xandy.y][xandy.x] = '\0';
			xandy.y++;
			xandy.x = 0;
		}
	}
	map_array[xandy.y] = (char *)malloc(1 * sizeof(char));
	map_array[xandy.y][0] = '\0';
	return (map_array);
}