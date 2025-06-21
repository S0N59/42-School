/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:17:49 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:17:55 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_door_open(t_vars *var)
{
	if (var->nb_obj <= 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
			var->door_open, var->door_x * 64, var->door_y * 64);
		if ((var->pos_x == var->door_x) && (var->pos_y == var->door_y))
		{
			ft_printf("Xorosh !\n");
			exit(0);
		}
	}
	return (0);
}
