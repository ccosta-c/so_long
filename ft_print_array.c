/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:46:13 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/24 18:05:14 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_array(t_windows *stu, char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stu->y_size)
	{
		while (array && array[i][j] != '\0')
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
}
