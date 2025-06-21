/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:36:32 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/15 12:36:34 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    here_doc(char *limiter, int argc)
{
    pid_t    reader;
    int        fd[2];
    char    *line;

    line = NULL;
    if (argc < 6)
        usage();
    if (pipe(fd) == -1)
        error();
    reader = fork();
    if (reader == 0)
    {
        close(fd[0]);
        while (get_next_line((int)line))
        {
            if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
                exit(0);
            write(fd[1], line, ft_strlen(line));
        }
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], 0);
        wait(NULL);
    }
}
