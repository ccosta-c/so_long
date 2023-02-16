/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:31 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/15 11:38:31 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	c_words(const char *s, char c)
{
	int	space;
	int	words;
	int	i;

	space = 1;
	words = 0;
	i = 0;
	while (s && s[i] != '\0')
	{
		if ((s[i] != c) && space == 1)
		{
			words += 1;
			space = 0;
		}
		if (space == 0 && s[i] == c)
		{
			space = 1;
		}
		i++;
	}
	return (words);
}

static char	*w_words(const char *s, char c)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while ((s[len] != '\0') && (s[len] != c))
	{
		len += 1;
	}
	word = (char *)malloc(len + 1);
	if (!word)
	{
		return (NULL);
	}
	word[len] = '\0';
	i = 0;
	while (len > i)
	{
		word[i] = *s;
		i++;
		s++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		nbr_words;
	char	**words_array;
	int		i;

	i = 0;
	nbr_words = c_words(s, c);
	words_array = (char **)malloc((nbr_words + 1) * sizeof(char *));
	if (!words_array)
	{
		return (NULL);
	}
	while (i < nbr_words)
	{
		while (*s != '\0' && *s == c)
		{
			s++;
		}
		words_array[i] = w_words(s, c);
		s = s + ft_strlen(words_array[i]);
		i++;
	}
	words_array[i] = NULL;
	return (words_array);
}
