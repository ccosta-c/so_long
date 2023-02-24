/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:18:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/24 20:22:44 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_animation(t_windows *windows, int x, int i, int j)
{
	if (x == 0)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_1, (j * 64), (i * 64));
	if (x == 100)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_2, (j * 64), (i * 64));
	if (x == 200)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_3, (j * 64), (i * 64));
	if (x == 300)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_4, (j * 64), (i * 64));
}

int     random_generator(void)
{
    int     random;

    srand (clock());
    random = rand();
    random = random % (4 - 1 + 1) + 1;
    return (random);
}

void change_enemies(t_windows *windows, char one, char two)
{
    int x;
    int y;
    int rand;

    rand = 0; 
    x = 0; 
    y = 0;
    while(y < windows->y_size) 
    {
        while(x < windows->x_size)
        {
            if(windows->render_array[y][x] == one)
            {
                rand = random_generator();
                if(rand == 1)
                {
                    if(check_enemy_move(windows, windows->render_array[y - 1][x]))
                    {
                        windows->render_array[y][x] = '0';
                        windows->render_array[y - 1][x] = two;
                    }
                }
                if(rand == 2)
                {
                    if(check_enemy_move(windows, windows->render_array[y + 1][x]))
                    {
                        windows->render_array[y][x] = '0';
                        windows->render_array[y + 1][x] = two;
                    }
                }
                if(rand == 3)
                {
                    if(check_enemy_move(windows, windows->render_array[y][x - 1]))
                    {
                        windows->render_array[y][x] = '0';
                        windows->render_array[y][x - 1] = two;
                    }
                }
                if(rand == 4)
                {
                    if(check_enemy_move(windows, windows->render_array[y][x + 1]))
                    {
                        windows->render_array[y][x] = '0';
                        windows->render_array[y][x + 1] = two;
                    }
                }
            }
            x++;
        }
        y++;
        x = 0;
    }
}

int		check_enemy_move(t_windows *windows, char c)
{
	if (c == '1' || c == 'C' || c == 'E' || c == 'S')
		return (0);
    if (c == 'I' || c == 'L')
		return (0);
    if (c == 'P')
    {
        ft_printf("AN ENEMY HIT YOU! GAME OVER!\n");
        end_game(windows);
    }
    return (1);
}