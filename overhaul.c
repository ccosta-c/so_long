/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overhaul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:21:37 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/03 12:14:24 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	changes(t_windows *windows)
{
	static int i;
	if(i == 5000)
	{
		enemy_trigger(windows);
		i = 0;
	}
	player_animation(windows, windows->y_player, windows->x_player);
	enemy_animation(windows);
	render_wall(windows);
	text_to_screen(windows);
	i++;
	return (0);
}