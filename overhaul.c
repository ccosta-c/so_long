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

int	changes(t_windows *stu)
{
	static int	i;

	if (i == 5000)
	{
		enemy_trigger(stu);
		i = 0;
	}
	player_animation(stu, stu->y_player, stu->x_player);
	enemy_animation(stu);
	render_wall(stu);
	text_to_screen(stu);
	i++;
	return (0);
}
