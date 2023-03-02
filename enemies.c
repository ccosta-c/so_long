/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:18:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/03/02 17:12:15 by ccosta-c         ###   ########.fr       */
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

void	enemy_animation(t_windows *windows, int i, int j)
{
	static int  x;
    
    if (x < 100)
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_1, (j * 64), (i * 64));
	if (x >= 100 && x < 200 )
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_2, (j * 64), (i * 64));
	if (x >= 200 && x < 300 )
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_3, (j * 64), (i * 64));
	if (x >= 300 && x < 400 )
		mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->enemy_4, (j * 64), (i * 64));
    if (x == 400)
		x = 0;
    x++;
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
    
    y = -1;
    while(++y < windows->y_size) 
    {
        x = -1;
        while(++x < windows->x_size)
        {
            if(windows->render_array[y][x] == one)
            {
                rand = random_generator();
                if(rand == 1)
                    enemy_movement_y(windows, y, x, two, rand);
                if(rand == 2)
                     enemy_movement_y(windows, y, x, two, rand);
                if(rand == 3)
                    enemy_movement_x(windows, y, x, two, rand);
                if(rand == 4)
                     enemy_movement_x(windows, y, x, two, rand);
            }
        }
    }
}

int		check_enemy_move(char c)
{
	if (c == '1' || c == 'C' || c == 'E' || c == 'S')
		return (0);
    if (c == 'I' || c == 'L')
		return (0);
    return (1);
}

void    enemy_movement_y(t_windows *windows, int y, int x, char two, int rand)
{
    if (rand == 1)
    {
        if(check_enemy_move(windows->render_array[y - 1][x]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y - 1][x] = two;
            enemy_animation(windows, y - 1, x);
        }
    }
     if (rand == 2)
    {
        if(check_enemy_move(windows->render_array[y + 1][x]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y + 1][x] = two;
            enemy_animation(windows, y + 1, x);
        }
    }
}

void    enemy_movement_x(t_windows *windows, int y, int x, char two, int rand)
{
    if (rand == 3)
    {
        if(check_enemy_move(windows->render_array[y][x - 1]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y][x - 1] = two;
            enemy_animation(windows, y, x - 1);
        }
    }
     if (rand == 4)
    {
        if(check_enemy_move(windows->render_array[y][x + 1]))
        {
            windows->render_array[y][x] = '0';
            mlx_put_image_to_window(windows->mlx_ptr, windows->win_ptr, windows->floor, (x * 64), (y * 64));
            windows->render_array[y][x + 1] = two;
            enemy_animation(windows, y, x + 1);
        }
    }
}