/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:51:11 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 13:24:17 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			*(char *)(dst + i) = *(char *)(src + i);
		}
	}
	else
	{
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
				i++;
		}
	}
	return (dst);
}
