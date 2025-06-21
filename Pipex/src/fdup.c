/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:37:17 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/29 14:20:58 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pip[1], 1);
	close(pipex.pip[0]);
	if (dup2(pipex.infile, 0) == -1)
		exit (1);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = search_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		print_error("First command is not found!\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	child2(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pip[0], 0);
	close(pipex.pip[1]);
	if (dup2(pipex.outfile, 1) == -1)
		exit(1);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = search_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		print_error("Second command is not found!\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
