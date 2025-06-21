/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:27:22 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 13:35:21 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (0);
		str[0] = 0;
		return (str);
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		i = 0;
		while (++i - 1 < len)
			*(str + i - 1) = *(s + start + i - 1);
		*(str + i - 1) = 0;
		return (str);
	}
}
