/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:16:44 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/01 11:43:48 by ccosta-c         ###   ########.fr       */
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
			return (1);
		j++;
	}
	return (i);
}

int	check_borders(char **map, t_windows *stu)
{
	if (check_line(map, 0, 0, stu))
		return (0);
	if (check_row(map, (stu->x_size - 1), 0, stu))
		return (0);
	if (check_line(map, 0, (stu->y_size - 1), stu))
		return (0);
	if (check_row(map, 0, 0, stu))
		return (0);
	return (1);
}

int	get_map_size(t_windows *stu, char *file)
{
	stu->y_size = get_height(file);
	convert_map_to_array(stu, file);
	stu->x_size = get_width(stu);
	if (stu->x_size == 0)
	{
		ft_printf("Lines width is not equal to all of the lines.\n");
		return (1);
	}
	ft_printf("Map Height - %d\n", stu->y_size);
	ft_printf("Map Width - %d\n", stu->x_size);
	ft_printf("--------------------------\n");
	return (0);
}

/*int get_width(char *file)
{
	char	*line;
	int 	reference;
	int		i;
	int		fd;

	i = 0;
	reference = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (reference == 0)
			reference = ft_strlenwithoutn(line);
		i = ft_strlenwithoutn(line);
		if (i != reference)
		{
			close(fd);
			return (1);
		}
		free (line);
	}
	free (line);
	close(fd);
	return (i);
}
*/