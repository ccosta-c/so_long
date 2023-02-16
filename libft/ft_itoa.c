/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:09:54 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/15 11:39:27 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	nbr_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		len += 1;
	}
	while (n != 0)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

static int	*ft_minimum_int(int *n, char *result, int *len)
{
	*(result + *len) = 48 + 8;
	*n = *n / 10;
	*n *= -1;
	*len -= 1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = nbr_len(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	len -= 1;
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == -2147483648)
		n = *(ft_minimum_int(&n, result, &len));
	while (n != 0)
	{
		result[len] = 48 + (n % 10);
		len -= 1;
		n = n / 10;
	}
	return (result);
}
