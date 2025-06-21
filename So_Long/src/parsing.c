/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:19:46 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:19:51 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_terminal(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
		exit(ft_printf("Wrong number of arguments\n"));
	while (argv[1][i])
	{
		if (argv[1][i] == '.' && (argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e'
			&& argv[1][i + 3] == 'r' && argv[1][i + 4] == '\0'))
			return ;
		i++;
	}
	exit(ft_printf("Wrong extension\n"));
}

char	**check_map(int fd, int nb_line)
{
	int		i;
	int		j;
	char	**map;
	size_t	len;

	i = -1;
	j = 0;
	if (nb_line == 0)
		exit(ft_printf("File empty\n"));
	map = malloc(sizeof(*map) * (nb_line + 1));
	if (!map)
		return (NULL);
	while (++i <= nb_line)
	{
		map[i] = get_next_line(fd);
		if (map[i] && map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
	}
	len = ft_strlen(map[0]);
	while (--i >= 0)
	{
		if (map[i] && ft_strlen(map[i]) != len)
			exit(ft_printf("Map not rectangle\n"));
	}
	return (map);
}

void	check_closed(char **map, int nb_line)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_strlen(*map) - 1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][len] != '1')
			exit(ft_printf("Map not closed\n"));
		j = -1;
		while (map[i][++j] && j < len)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				exit(ft_printf("Unexpected element\n"));
			if (i == 0 || i == nb_line - 1)
			{
				if (map[i][j] != '1')
					exit(ft_printf("Map not closed\n"));
			}
		}
	}
}

void	check_elements(char **map)
{
	int	i;
	int	j;
	int	element_e;
	int	element_p;
	int	element_c;

	i = -1;
	element_e = 0;
	element_p = 0;
	element_c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				element_e += 1;
			if (map[i][j] == 'P')
				element_p += 1;
			if (map[i][j] == 'C')
				element_c += 1;
		}
	}
	if ((element_e != 1) || (element_p != 1) || (element_c <= 0))
		exit(ft_printf("Wrong number of element\n"));
}

char	**parsing(int argc, char **argv, t_path *path)
{
	int		fd;
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	path->nb_line = 0;
	check_terminal(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(ft_printf("File problem\n"));
	path->nb_line = count_line(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = check_map(fd, path->nb_line);
	check_elements(map);
	check_closed(map, path->nb_line);
	path->cpy = ft_tabdup(map, *path);
	check_pathing(path);
	free_map(path->cpy);
	return (map);
}
