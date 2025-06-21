/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:16:10 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:16:16 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	char	*gnl;
	int		nb_line;

	nb_line = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		nb_line++;
	}
	return (nb_line);
}
