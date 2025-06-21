/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:47:43 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 13:32:07 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && !needle)
		return (0);
	if (!haystack || !needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack [i + j] && needle[j]
			&& i + j < len && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
