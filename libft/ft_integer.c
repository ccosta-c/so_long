/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:59:06 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/18 15:34:23 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_integer(long nb)
{
	int		count;
	char	*base;

	base = "0123456789";
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += ft_char('-');
	}
	if (nb >= 10)
	{
		count += ft_integer(nb / 10);
		count += ft_integer(nb % 10);
	}
	if (nb < 10)
	{
		count += ft_char(*(base + nb));
	}
	return (count);
}
