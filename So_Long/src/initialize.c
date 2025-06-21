/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:17:26 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:17:33 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_values(t_vars *var)
{
	int	i;
	int	j;

	var->width = 64;
	var->height = 64;
	i = 0;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == 'P')
			{
				var->pos_x = j;
				var->pos_y = i;
			}
			if (var->map[i][j] == 'C')
				var->nb_obj += 1;
			if (var->map[i][j] == 'E')
			{
				var->door_x = j;
				var->door_y = i;
			}
		}
	}
}

void	initialize_map(t_vars *var)
{
	var->nb_obj = 0;
	initialize_values(var);
	print_floor(var);
	print_wall(var);
	print_door(var);
	print_player(var);
	print_key(var);
	var->door_open = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/door_open.xpm", &(var)->width, &(var)->height);
	var->backward_one = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/backward_one.xpm", &(var)->width, &(var)->height);
	var->backward_two = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/backward_two.xpm", &(var)->width, &(var)->height);
	var->left_one = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/left_one.xpm", &(var)->width, &(var)->height);
	var->left_two = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/left_two.xpm", &(var)->width, &(var)->height);
	var->forward_one = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/forward_one.xpm", &(var)->width, &(var)->height);
	var->forward_two = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/forward_two.xpm", &(var)->width, &(var)->height);
	var->right_one = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/right_one.xpm", &(var)->width, &(var)->height);
	var->right_two = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./img/right_two.xpm", &(var)->width, &(var)->height);
}
