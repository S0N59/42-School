/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:14:28 by nkostany          #+#    #+#             */
/*   Updated: 2023/02/22 14:10:05 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_hex(unsigned int i, int c)
{
	if (i > 15)
	{
		ft_itoa_hex(i / 16, c);
		ft_itoa_hex(i % 16, c);
	}
	else
	{
		if (i < 10)
			ft_putchar (i + '0');
		else if (c == 'x')
			ft_putchar (i - 10 + 'a');
		else
			ft_putchar (i - 10 + 'A');
	}
}

int	ft_type_hex(unsigned int i, int c)
{
	int				count;
	unsigned int	tmp;

	count = 0;
	tmp = i;
	if (tmp == 0)
		count++;
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	ft_itoa_hex (i, c);
	return (count);
}
