/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:36:16 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/15 12:36:18 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t    child_process(int pipe_fd[2], char argv[], char **envp)
{
    pid_t    pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
        execute(argv, envp);
        exit(0);
    }
    return (pid);
}

void    wait_process(int pipe_fd[2], pid_t *child_pids, int child_count)
{
    int    j;

    j = 0;
    while (j < child_count)
    {
        waitpid(child_pids[j], NULL, 0);
        j++;
    }
    close(pipe_fd[1]);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    free(child_pids);
}