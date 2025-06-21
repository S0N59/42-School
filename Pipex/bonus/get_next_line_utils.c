/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:28:45 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/30 11:18:05 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = ft_strlen (dst);
	j = 0;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dst);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*res;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	if (!s2)
		return (0);
	res = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == 0)
		return (0);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	free (s1);
	return (res);
}
