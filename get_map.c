/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:26:28 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/01 14:14:27 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	convert_map_to_array(t_windows *windows, char *file)
{
	int				fd;
	char			*line;
	t_coordinates	xandy;
	
	fd = open(file, O_RDONLY);
	line = "start";
	xandy.x = 0;
	xandy.y = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			windows->render_array[xandy.y] = (char *)malloc((windows->x_size + 1) * sizeof(char));
		while (line && line[xandy.x] != '\0' && line[xandy.x] != '\n')
		{
			windows->render_array[xandy.y][xandy.x] = line[xandy.x];
			xandy.x++;
		}
		if (line)
		{
			windows->render_array[xandy.y][xandy.x] = '\0';
			xandy.y++;
			xandy.x = 0;
		}
	}
	windows->render_array[xandy.y] = (char *)malloc(1 * sizeof(char));
	windows->render_array[xandy.y][0] = '\0';
	close(fd);
	free(line);
	return (0);
}

//DAR FREE AO LINE