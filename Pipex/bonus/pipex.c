/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:36:51 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/15 12:36:52 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    pipe_process(int i, int argc, char **argv, char **envp)
{
    int        pipe_fd[2];
    int        fileout;
    int        child_count;
    pid_t    *child_pids;
    int        j;

    child_count = argc - i - 2;
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(1);
    }
    fileout = open_file(argv[argc - 1], 1);
    child_pids = malloc(child_count * sizeof(pid_t));
    j = 0;
    while (j < child_count)
    {
        child_pids[j] = child_process(pipe_fd, argv[i], envp);
        i++;
        j++;
    }
    close(pipe_fd[0]);
    dup2(fileout, 1);
    close(fileout);
    wait_process(pipe_fd, child_pids, child_count);
}

int    main(int argc, char **argv, char **envp)
{
    int    i;
    int    filein;

    if (argc >= 5)
    {
        if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        {
            here_doc(argv[2], argc);
            i = 3;
        }
        else
        {
            filein = open_file(argv[1], 2);
            dup2(filein, 0);
            i = 2;
        }
        pipe_process(i, argc, argv, envp);
    }
    else
        usage();
}