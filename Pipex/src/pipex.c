/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:38:37 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/29 14:21:26 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		print_error("Invalid number of arguments!\n");
	get_file(&pipex, av, ac);
	if (pipe(pipex.pip) == -1)
		print_error("Pipex error!\n");
	pipex.cmd_paths = get_path(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		print_error("Process error!\n");
	if (pipex.pid1 == 0)
		child1(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		print_error("Process error!\n");
	if (pipex.pid2 == 0)
		child2(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pip[0]);
	close(pipex->pip[1]);
}
