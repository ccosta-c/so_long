/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:46:13 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/15 17:10:30 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_array (char **array)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while(array[i][j] != '\0') 
  {
    while(array[i][j] != '\0')
	  {
      printf("%c ", array[i][j]);
	    j++;
    }
    i++;
    j = 0;
	printf("\n");
  }
}