/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:09 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 17:50:51 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != c)
			++s;
	}
	return (word_count);
}

static void	alloc(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*str;

	str = s;
	tab_p = tab;
	while (*str)
	{
		while (*s == sep)
			++s;
		str = s;
		while (*str && *str != sep)
			++str;
		if (*str == sep || str > s)
		{
			*tab_p = ft_substr(s, 0, str - s);
			s = str;
			++tab_p;
		}
	}
	*tab_p = 0;
}

static char	**ft_free(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		j;

	j = -1;
	if (!s)
		return (0);
	size = wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
	{
		ft_free(str, j);
		return (0);
	}
	alloc(str, s, c);
	return (str);
}
