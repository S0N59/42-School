/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:40:35 by nkostany          #+#    #+#             */
/*   Updated: 2023/02/22 14:03:53 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_checker(va_list arguments, int c)
{
	int	number;

	number = 0;
	if (c == 'i' || c == 'd')
		number = ft_putnbr(va_arg(arguments, int));
	else if (c == 'c')
		number = ft_putchar(va_arg(arguments, int));
	else if (c == 's')
		number = ft_putstr(va_arg(arguments, char *));
	else if (c == '%')
		number = print_for_percent();
	else if (c == 'x' || c == 'X')
		number = ft_type_hex(va_arg(arguments, unsigned int), c);
	else if (c == 'p')
	{
		number += write(1, "0x", 2);
		number += put_ptr(va_arg(arguments, unsigned long long));
	}
	else if (c == 'u')
		number = ft_putnbr_uns((unsigned int)va_arg(arguments, unsigned int));
	return (number);
}

int	ft_printf(const char *s, ...)
{
	va_list	arguments;
	int		i;
	int		print_nbr;

	i = 0;
	print_nbr = 0;
	va_start(arguments, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			print_nbr += arg_checker(arguments, s[i + 1]);
			i++;
		}
		else
			print_nbr += ft_putchar(s[i]);
			i++;
	}
	va_end(arguments);
	return (print_nbr);
}
