/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:19 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/15 11:39:35 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		x;

	x = nmemb * size;
	ptr = malloc(x);
	if (!ptr)
		return (NULL);
	while (--x >= 0)
		*(ptr + x) = '\0';
	return ((void *)ptr);
}
