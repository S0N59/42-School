/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:20:53 by nkostany          #+#    #+#             */
/*   Updated: 2023/02/22 14:04:55 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "Libft/libft.h"

int	arg_checker(va_list arguments, int c);

int	ft_printf(const char *s, ...);

int	print_for_percent(void);

int	ft_putchar(char c);

int	ft_putnbr(int n);

int	ft_putstr(char *c);

int	ft_type_hex(unsigned int i, int c);

int	ptr_len(unsigned long long n);

int	print_ptr(unsigned long long n);

int	put_ptr(unsigned long long n);

int	ft_putnbr_uns(unsigned int n);

#endif
