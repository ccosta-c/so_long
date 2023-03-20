/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:46:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/06 15:39:04 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(t_windows *stu, char *file)
{
	stu->y_size = get_height(file);
	if (stu->y_size == -1)
	{
		ft_printf("\033[1;31mERROR!\nFile doesn't exist!\033[0m\n");
		return (1);
	}
	convert_map_to_array(stu, file);
	stu->x_size = get_width(stu);
	if (stu->x_size == 0)
	{
		ft_printf("\033[1;31mERROR!\nLines width is not equal.\033[0m\n");
		return (1);
	}
	ft_printf("Map Height - %d\n", stu->y_size);
	ft_printf("Map Width - %d\n", stu->x_size);
	ft_printf("--------------------------\n");
	return (0);
}

int	get_height(char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	get_width(t_windows *stu)
{
	int	reference;
	int	j;
	int	i;

	reference = 0;
	j = 0;
	i = 0;
	while (j < stu->y_size)
	{
		i = ft_strlenwithoutn(stu->render_array[j]);
		if (reference == 0)
			reference = i;
		if (reference != i)
			return (0);
		j++;
	}
	return (i);
}

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
