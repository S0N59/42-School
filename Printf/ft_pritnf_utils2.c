/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pritnf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:15 by nkostany          #+#    #+#             */
/*   Updated: 2023/02/22 14:12:19 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	*message;

	len = 0;
	message = ft_itoa(n);
	len = ft_putstr(message);
	free (message);
	return (len);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
	return (i);
}
