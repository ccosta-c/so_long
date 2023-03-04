/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:18:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/03 12:26:36 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void enemy_trigger(t_windows *windows)
{
    static int e;
    
    if(e % 2 == 0)
		change_enemies(windows, 'I', 'L');
	if(e % 2 != 0)
		change_enemies(windows, 'L', 'I');
    e++;
}

void	enemy_animation(t_windows *windows)
{
    int x;
    int y;
    static int q;

    y = -1;
    while(++y < windows->y_size) 
    {
        x = -1;
        while(++x < windows->x_size)
        {
            if(windows->render_array[y][x] == 'I' || windows->render_array[y][x] == 'L')
            {
                if (q < 1000)
                    mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_1, (x * 64), (y * 64));
                if (q >= 1000 && q < 2000)
                    mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_2, (x * 64), (y * 64));
                if (q >= 2000 && q < 3000)
                    mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_3, (x * 64), (y * 64));
                if (q >= 3000 && q <= 4000)
                    mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_4, (x * 64), (y * 64));
                if (q == 4000)
                    q = 0;
            }
        }
    }
    q++;
}

void    random_generator(t_windows *windows)
{
    srand (clock());
    windows->rand = rand();
    windows->rand = windows->rand % (4 - 1 + 1) + 1;
}

void change_enemies(t_windows *windows, char one, char two)
{
    int x;
    int y;
    
    y = -1;
    while(++y < windows->y_size) 
    {
        x = -1;
        while(++x < windows->x_size)
        {
            if(windows->render_array[y][x] == one)
            {
                random_generator(windows);
                ft_printf("%d", windows->rand);
                if(windows->rand == 1)
                    enemy_movement_y(windows, y, x, two);
                if(windows->rand == 2)
                     enemy_movement_y(windows, y, x, two);
                if(windows->rand == 3)
                    enemy_movement_x(windows, y, x, two);
                if(windows->rand == 4)
                     enemy_movement_x(windows, y, x, two);
            }
        }
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
        ft_printf("AN ENEMY HIT YOU!\n");
        end_game(windows);
    }
    return (1);
}

void    enemy_movement_y(t_windows *windows, int y, int x, char two)
{
    if (windows->rand == 1)
    {
        if(check_enemy_move(windows, windows->render_array[y - 1][x]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y - 1][x] = two;
        }
    }
     if (windows->rand == 2)
    {
        if(check_enemy_move(windows, windows->render_array[y + 1][x]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y + 1][x] = two;
        }
    }
}

void    enemy_movement_x(t_windows *windows, int y, int x, char two)
{
    if (windows->rand == 3)
    {
        if(check_enemy_move(windows, windows->render_array[y][x - 1]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y][x - 1] = two;
        }
    }
     if (windows->rand == 4)
    {
        if(check_enemy_move(windows, windows->render_array[y][x + 1]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y][x + 1] = two;
        }
    }
}