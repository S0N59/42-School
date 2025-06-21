/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:07:24 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 13:25:50 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	str;

	str = ft_strlen(s);
	if (!s)
		return ;
	write (fd, s, str);
}
