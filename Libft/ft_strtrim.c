/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:19 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 14:05:46 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_char_into_set_checker(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	skizb;
	size_t	verj;
	size_t	i;

	skizb = 0;
	i = 0;
	while (s1[skizb] && ft_char_into_set_checker(s1[skizb], set))
		skizb++;
	verj = ft_strlen(s1);
	while (verj > skizb && ft_char_into_set_checker(s1[verj - 1], set))
		verj--;
	str = (char *)malloc(sizeof(*s1) * (verj - skizb + 1));
	if (!str)
		return (0);
	while (skizb < verj)
		str[i++] = s1[skizb++];
	str[i] = 0;
	return (str);
}
