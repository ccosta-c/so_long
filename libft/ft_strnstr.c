/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:05:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/11/14 20:02:56 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (little[i] == '\0')
	{
		return ((char *)big);
	}
	while ((i < len))
	{
		x = 0;
		while (((i + x) < len) && (big[i + x] == little[x]))
		{
			if (little[x + 1] == '\0')
			{
				return ((char *)(big + i));
			}
			x++;
		}
		i++;
	}
	return (0);
}
