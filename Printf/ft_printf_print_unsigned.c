/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:20:36 by nkostany          #+#    #+#             */
/*   Updated: 2023/02/22 15:20:38 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_u(unsigned int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
	}	
	else
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
}

static int	ft_length(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_uns(unsigned int n)
{
	ft_putnbr_u(n);
	return (ft_length(n));
}
