/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:58:20 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/26 17:52:37 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long	itoa_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		while (nb < -9)
		{
			nb = nb / 10;
			len++;
		}
		len++;
	}
	if (nb > 0)
	{
		while (nb > 9)
		{
			nb = nb / 10;
			len++;
		}
		len++;
	}
	return (len);
}

static char	*ft_alloc(char *s)
{
	s = malloc(2);
	if (!s)
		return (0);
	s[0] = 48;
	s[1] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	long	i;
	char	*str;
	long	nb;

	nb = n;
	i = itoa_len(n);
	if (n > 0)
		i = itoa_len(n) - 1;
	if (nb == 0)
		return (ft_alloc(0));
	str = malloc(i * sizeof(char) + 1);
	if (str == 0)
		return (0);
	str[i--] = 0;
	if (nb < 0)
	{
		*(str + 0) = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
