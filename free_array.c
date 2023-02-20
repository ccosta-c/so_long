/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:19:50 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/20 14:30:20 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array, int y)
{
	int	i;

  	i = 0;
  	while(i < y) 
  	{
    	free(array[i]);
		i++;
  	}
 	free(array);
}