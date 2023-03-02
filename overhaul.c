/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overhaul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:21:37 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/02 17:08:15 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	changes(t_windows *windows)
{
	static int i;
	if(i == 15000)
	{
		enemy_trigger(windows);
		i = 0;
	}
	player_animation(windows, windows->y_player, windows->x_player);
	windows->str_collectibles = put_text("Collectibles Collected: ", windows->collected);
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 32, 0xFFFFFF, windows->str_collectibles);
	windows->str_moves = put_text("Moves: ", windows->moves);
	mlx_string_put(windows->mlx_ptr, windows->win_ptr, 10, 20, 0xFFFFFF, windows->str_moves);
	free(windows->str_collectibles);
	free(windows->str_moves);
	i++;
	return (0);
}