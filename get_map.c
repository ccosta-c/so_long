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
	char			*lines;
	t_coordinates	xandy;
	
	windows->render_array = (char **)malloc((windows->y_size) * sizeof(char*));
	if (!(windows->render_array))
		return (1);
	fd = open(file, O_RDONLY);
	xandy.y = 0;
	while (1)
	{
		lines = get_next_line(fd);
		xandy.x = 0;
		if (!lines)
			break ;
		windows->render_array[xandy.y] = (char *)malloc((ft_strlenwithoutn(lines) + 1) * sizeof(char));
		if(!(windows->render_array[xandy.y]))
		{
			close(fd);
			free(lines);
			return(1);
		}
		while (lines && lines[xandy.x] != '\0' && lines[xandy.x] != '\n')
		{
			windows->render_array[xandy.y][xandy.x] = lines[xandy.x];
			xandy.x++;
		}
		windows->render_array[xandy.y][xandy.x] = '\0';
		xandy.y++;
		free(lines);
	}
	close(fd);
	free(lines);
	return (0);
}