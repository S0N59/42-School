/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:07:24 by nkostany          #+#    #+#             */
/*   Updated: 2023/02/22 14:07:57 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	print_ptr(unsigned long long n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n >= 16)
	{
		print_ptr(n / 16);
		print_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar (n + '0');
		else
			ft_putchar (n - 10 + 'a');
	}
	return (0);
}

int	put_ptr(unsigned long long n)
{
	int	len;

	len = ptr_len(n);
	print_ptr(n);
	return (len);
}
