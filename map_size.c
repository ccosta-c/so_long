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
	free(line);
	close(fd);
	return(i);
}

int	get_width(t_windows *windows)
{
	int	reference;
	int	j;
	int	i;

	reference = 0;
	j = -1;
	i= 0;
	while (j++ < windows->y_size)
	{
		while ((windows->render_array[j][i]) != '\0')
			i++;
		if(reference == 0)
			reference = i;
		if (reference != i)
			return (1);	
	}
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
	windows->x_size = get_width(windows);
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