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

int	convert_map_to_array(t_windows *stu, char *file)
{
	int				fd;
	char			*lines;
	t_coordinates	xandy;

	stu->render_array = (char **)malloc((stu->y_size) * sizeof(char *));
	if (!(stu->render_array))
		return (1);
	fd = open(file, O_RDONLY);
	lines = 0;
	xandy.y = 0;
	xandy.x = 0;
	get_lines(stu, fd, lines, xandy);
	close(fd);
	free(lines);
	return (0);
}

void	get_lines(t_windows *stu, int fd, char *lines, t_coordinates xandy)
{
	while (1)
	{
		lines = get_next_line(fd);
		xandy.x = 0;
		if (!lines)
			break ;
		stu->render_array[xandy.y] = (char *)malloc((
					ft_strlenwithoutn(lines) + 1) * sizeof(char));
		if (!(stu->render_array[xandy.y]))
		{
			close(fd);
			free(lines);
			return ;
		}
		while (lines && lines[xandy.x] != '\0' && lines[xandy.x] != '\n')
		{
			stu->render_array[xandy.y][xandy.x] = lines[xandy.x];
			xandy.x++;
		}
		stu->render_array[xandy.y][xandy.x] = '\0';
		xandy.y++;
		free(lines);
	}
}
