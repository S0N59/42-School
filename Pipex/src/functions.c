/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcitons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:38:05 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/29 14:21:11 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_command(char **path, char *cmd)
{
	char	*mem;
	char	*command;

	while (*path)
	{
		if (ft_strchr(cmd, '/') == 0)
		{
			mem = ft_strjoin(*path, "/");
			command = ft_strjoin(mem, cmd);
			free(mem);
			if (access(command, X_OK) == 0)
				return (command);
			free(command);
		}
		else if (ft_strchr(cmd, '/') != 0)
		{
			command = cmd;
			if (access(command, X_OK) == 0)
				return (command);
		}
		path++;
	}
	return (NULL);
}

char	**get_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (ft_split (*envp + 5, ':'));
}

void	get_file(t_pipex *pipex, char **av, int ac)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		ft_putstr_fd("Infile error!\n",2);
	pipex->outfile = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (pipex->outfile == -1)
		print_error("Outfile error!\n");
}
