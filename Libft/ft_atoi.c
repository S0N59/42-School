/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:24:14 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 17:51:07 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
			i++;
	if (str[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48);
	return (neg * res);
}
