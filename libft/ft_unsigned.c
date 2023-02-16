/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:59:06 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/18 15:34:51 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_unsigned(unsigned int nb)
{
	int		count;
	char	*base;

	base = "0123456789";
	count = 0;
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
