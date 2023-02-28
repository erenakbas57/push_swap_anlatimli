/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:28:57 by makbas            #+#    #+#             */
/*   Updated: 2022/10/19 18:02:32 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	c_amount(char const *s, char c)
{
	size_t	index;
	int		amount;

	amount = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			amount++;
		index++;
	}
	return (amount);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	next;
	char	**str_series;

	if (s == 0)
		return (NULL);
	str_series = malloc(sizeof(char *) * (c_amount(s, c) + 1));
	if (str_series == 0)
		return (NULL);
	index = 0;
	while (*s)
	{
		next = ft_str(s, c);
		if (next)
		{
			str_series[index] = ft_substr(s, 0, next);
			s += next;
			index++;
		}
		else
			s++;
	}
	str_series[index] = 0;
	return (str_series);
}
