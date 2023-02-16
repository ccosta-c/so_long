/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:33:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/15 11:38:23 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*s;
	unsigned int	src_len;
	unsigned int	dst_len;
	unsigned int	i;
	unsigned int	sol;

	s = (char *)src;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size > dst_len)
		sol = src_len + dst_len;
	else
		sol = size + src_len;
	while (s[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = s[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (sol);
}
