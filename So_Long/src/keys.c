/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:18:59 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:19:03 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_escape(t_vars *var)
{
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	exit(0);
	return (0);
}

void	ft_backward(t_vars *var)
{
	if (var->map[var->pos_y - 1][var->pos_x] != '1')
	{
		if (var->map[var->pos_y][var->pos_x] == 'E')
			print_door(var);
		else
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->floor, var->pos_x * 64, var->pos_y * 64);
		if (var->pos_y % 2 == 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->backward_one, var->pos_x * 64, (var->pos_y - 1) * 64);
		else if (var->pos_y % 2 != 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->backward_two, var->pos_x * 64, (var->pos_y - 1) * 64);
		if (var->map[var->pos_y - 1][var->pos_x] == 'C')
		{
			var->nb_obj -= 1;
			var->map[var->pos_y - 1][var->pos_x] = '0';
		}
		var->nb_moves++;
		printf("Move : %d\n", var->nb_moves);
		var->pos_y = var->pos_y - 1;
	}
}

void	ft_left(t_vars *var)
{
	if (var->map[var->pos_y][var->pos_x - 1] != '1')
	{
		if (var->map[var->pos_y][var->pos_x] == 'E')
			print_door(var);
		else
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->floor, var->pos_x * 64, var->pos_y * 64);
		if (var->pos_x % 2 == 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->left_one, (var->pos_x - 1) * 64, var->pos_y * 64);
		else if (var->pos_x % 2 != 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->left_two, (var->pos_x - 1) * 64, var->pos_y * 64);
		if (var->map[var->pos_y][var->pos_x - 1] == 'C')
		{
			var->nb_obj -= 1;
			var->map[var->pos_y][var->pos_x - 1] = '0';
		}
		var->nb_moves++;
		printf("Move : %d\n", var->nb_moves);
		var->pos_x = var->pos_x - 1;
	}
}

void	ft_forward(t_vars *var)
{
	if (var->map[var->pos_y + 1][var->pos_x] != '1')
	{
		if (var->map[var->pos_y][var->pos_x] == 'E')
			print_door(var);
		else
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->floor, var->pos_x * 64, var->pos_y * 64);
		if (var->pos_y % 2 == 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->forward_one, var->pos_x * 64, (var->pos_y + 1) * 64);
		else if (var->pos_y % 2 != 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->forward_two, var->pos_x * 64, (var->pos_y + 1) * 64);
		if (var->map[var->pos_y + 1][var->pos_x] == 'C')
		{
			var->nb_obj -= 1;
			var->map[var->pos_y + 1][var->pos_x] = '0';
		}
		var->nb_moves++;
		printf("Move : %d\n", var->nb_moves);
		var->pos_y = var->pos_y + 1;
	}
}

void	ft_right(t_vars *var)
{
	if (var->map[var->pos_y][var->pos_x + 1] != '1')
	{
		if (var->map[var->pos_y][var->pos_x] == 'E')
			print_door(var);
		else
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->floor, var->pos_x * 64, var->pos_y * 64);
		if (var->pos_x % 2 == 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->right_one, (var->pos_x + 1) * 64, var->pos_y * 64);
		else if (var->pos_x % 2 != 0)
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
				var->right_two, (var->pos_x + 1) * 64, var->pos_y * 64);
		if (var->map[var->pos_y][var->pos_x + 1] == 'C')
		{
			var->nb_obj -= 1;
			var->map[var->pos_y][var->pos_x + 1] = '0';
		}
		var->nb_moves++;
		printf("Move : %d\n", var->nb_moves);
		var->pos_x = var->pos_x + 1;
	}
}
