/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:16:44 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/27 19:12:15 by ccosta-c         ###   ########.fr       */
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
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (i);
}

int		check_borders(char **map, t_windows *windows)
{
	if (check_line(map, 0, 0, windows))
		return (0);
	if (check_row(map, (windows->x_size - 1), 0, windows))
		return (0);	
	if (check_line(map, 0, (windows->y_size - 1), windows))
		return (0);
	if (check_row(map, 0, 0, windows))
		return (0);	
	return (1);
}

int	get_map_size(t_windows *windows, char *file)
{
	windows->y_size = get_height(file);
	windows->x_size = get_width(file);
	if (windows->x_size == 0)
	{
		ft_printf("Lines width is not equal to all of the lines.\n");
		return (1);
	}
	ft_printf("Map Height - %d\n", windows->y_size);
	ft_printf("Map Width - %d\n", windows->x_size);
	ft_printf("--------------------------\n");
	return (0);
}