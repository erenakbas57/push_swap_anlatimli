/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:44:26 by makbas            #+#    #+#             */
/*   Updated: 2023/02/24 17:16:47 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

long	ft_atoi(const char *str);

int		ft_isdigit(int c);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
