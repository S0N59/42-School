/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:16:46 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:16:53 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_tabdup(char **s1, t_path p)
{
	int		i;
	int		j;
	char	**dest;

	i = -1;
	dest = NULL;
	dest = (char **) malloc ((p.nb_line + 1) * sizeof(char *));
	while (s1[++i] && (ft_strlen(s1[i]) > 1))
		dest[i] = (char *) malloc ((ft_strlen(s1[i]) + 1) * sizeof(char));
	dest[i] = 0;
	if (!dest)
		return (0);
	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (s1[i][++j])
			dest[i][j] = s1[i][j];
		dest[i][j] = '\0';
	}
	return (dest);
}
