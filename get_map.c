/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:26:28 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/23 15:42:17 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**convert_map_to_array(t_windows windows, char *file)
{
	char 	**map_array;
	int		fd;
	char	*line;
	t_coordinates xandy;
	
	fd = open(file, O_RDONLY);
	line = "start";
	xandy.x = 0;
	xandy.y = 0; 
	map_array = (char **)malloc((windows.y_size + 1) * sizeof(char*));
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			map_array[xandy.y] = (char *)malloc((windows.x_size + 1) * sizeof(char));
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
	close(fd);
	return (map_array);
}