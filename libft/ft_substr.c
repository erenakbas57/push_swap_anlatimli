/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:09:06 by makbas            #+#    #+#             */
/*   Updated: 2022/10/16 20:13:01 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	bt;
	char	*str;

	if (s == NULL)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	bt = 0;
	while ((bt < len) && (s[bt + start] != '\0'))
		bt++;
	str = (char *)malloc((sizeof(char) * bt) + 1);
	if (str == NULL)
		return (0);
	while (i < bt)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
