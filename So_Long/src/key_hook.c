/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:18:27 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:18:31 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_escape(vars);
	if (keycode == 13)
		ft_backward(vars);
	if (keycode == 0)
		ft_left(vars);
	if (keycode == 1)
		ft_forward(vars);
	if (keycode == 2)
		ft_right(vars);
	return (0);
}
