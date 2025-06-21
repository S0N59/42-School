/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:37:27 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/15 12:37:29 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char    *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    int        i;
    char    *part_path;

    i = 0;
    while (ft_strnstr(envp[i], "PATH=", 5) == 0)
        i++;
    paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (paths[i])
    {	
		if (ft_strchr(cmd, '/') == 0)
		{
        	part_path = ft_strjoin(paths[i], "/");
        	path = ft_strjoin(part_path, cmd);
        	free(part_path);
        	if (access(path, F_OK) == 0)
            return (path);
        	free(path);
        	i++;
   		}
	}
    i = -1;
    while (paths[++i])
        free(paths[i]);
    free(paths);
    return (0);
}

void    usage(void)
{
    ft_putstr_fd("Bad arguments.\n", 2);
    exit(1);
}

int    open_file(char *argv, int i)
{
    int    file;

    file = 0;
    if (i == 0)
        file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
    else if (i == 1)
        file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else if (i == 2)
        file = open(argv, O_RDONLY, 0777);
    if (file == -1)
		usage();
    return (file);
}