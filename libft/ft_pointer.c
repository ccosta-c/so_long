/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:33:23 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/18 15:34:28 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_address(unsigned long address)
{
	int	count;

	if (!address)
		return (ft_string("(nil)"));
	count = 0;
	count += ft_string("0x");
	count += ft_hex(address, 'x');
	return (count);
}
