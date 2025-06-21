/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:20:42 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:20:46 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_vars *var)
{
	int	i;
	int	j;

	var->wall = mlx_xpm_file_to_image(var->mlx_ptr, \
		WALL, &var->width, &var->height);
	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == '1')
				mlx_put_image_to_window(var->mlx_ptr, \
					var->win_ptr, var->wall, j * 64, i * 64);
		}
	}
}

void	print_floor(t_vars *var)
{
	int	i;
	int	j;

	var->floor = mlx_xpm_file_to_image(var->mlx_ptr, \
		FLOOR, &var->width, &var->height);
	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
			mlx_put_image_to_window(var->mlx_ptr, \
				var->win_ptr, var->floor, j * 64, i * 64);
	}
}

void	print_door(t_vars *var)
{
	var->door_closed = mlx_xpm_file_to_image(var->mlx_ptr, \
		DOOR, &var->width, &var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
		var->door_closed, var->door_x * 64, var->door_y * 64);
}

void	print_key(t_vars *var)
{
	int	i;
	int	j;

	var->red_key = mlx_xpm_file_to_image(var->mlx_ptr, \
		KEY, &var->width, &var->height);
	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == 'C')
				mlx_put_image_to_window(var->mlx_ptr, \
					var->win_ptr, var->red_key, j * 64, i * 64);
		}
	}
}

void	print_player(t_vars *var)
{
	int	i;
	int	j;

	var->forward_one = mlx_xpm_file_to_image(var->mlx_ptr, \
		PLAYER, &var->width, &var->height);
	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == 'P')
				mlx_put_image_to_window(var->mlx_ptr, \
					var->win_ptr, var->forward_one, j * 64, i * 64);
		}
	}
}
