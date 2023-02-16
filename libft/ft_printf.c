/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/18 15:34:33 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_conversion(const char *str, va_list var_args)
{
	int	count;

	count = 0;
	if (*(str + 1) == '%')
		count += ft_char('%');
	if (*(str + 1) == 'i' || *(str + 1) == 'd')
		count += ft_integer(va_arg(var_args, int));
	if (*(str + 1) == 'x' || *(str + 1) == 'X')
		count += ft_hex(va_arg(var_args, unsigned int), *(str + 1));
	if (*(str + 1) == 'c')
		count += ft_char(va_arg(var_args, unsigned int));
	if (*(str + 1) == 's')
		count += ft_string(va_arg(var_args, char *));
	if (*(str + 1) == 'u')
		count += ft_unsigned(va_arg(var_args, unsigned int));
	if (*(str + 1) == 'p')
		count += ft_address(va_arg(var_args, unsigned long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	size_t	count;

	va_start(var_args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += check_conversion(str, var_args);
			str++;
		}
		else
		{
			count += ft_char(*str);
		}
		str++;
		va_end(var_args);
	}
	return (count);
}