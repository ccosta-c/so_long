/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:46:19 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/15 11:39:54 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	chr;

	chr = c;
	str = (unsigned char *)s;
	i = 0;
	while (str[i] != chr && (i < (n - 1)))
	{
		i++;
	}
	if (str[i] == chr)
	{
		return (&str[i]);
	}
	return (0);
}
