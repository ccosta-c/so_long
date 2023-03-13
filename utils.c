/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:42:16 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/05 21:52:50 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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

char	*put_text(char *text, int nbr)
{
	char	*nbr_str;
	char	*str;

	nbr_str = ft_itoa(nbr);
	str = ft_strjoin(text, nbr_str);
	free(nbr_str);
	return (str);
}

void	random_generator(t_windows *stu)
{
	srand(clock());
	stu->rand = rand();
	stu->rand = stu->rand % (4 - 1 + 1) + 1;
}

void	text_to_screen(t_windows *stu)
{
	stu->str_collectibles = put_text("Collectibles Collected: ",
			stu->collected);
	stu->str_total_collectibles = put_text("/",
			stu->nbr_collectibles);
	stu->str_join_collectibles = ft_strjoin(stu->str_collectibles,
			stu->str_total_collectibles);
	mlx_string_put(stu->mlx_ptr, stu->win_ptr, 10, 32, 0xFFFFFF,
		stu->str_join_collectibles);
	stu->str_moves = put_text("Moves: ", stu->moves);
	mlx_string_put(stu->mlx_ptr, stu->win_ptr, 10, 20, 0xFFFFFF,
		stu->str_moves);
	free(stu->str_total_collectibles);
	free(stu->str_join_collectibles);
	free(stu->str_collectibles);
	free(stu->str_moves);
}
