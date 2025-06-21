#include "pipex_bonus.h"

void    error(void)
{
    perror("Error");
    exit(1);
}

void    execute(char *argv, char **envp)
{
    char    **cmd;
    int        i;
    char    *path;

    i = -1;
    cmd = ft_split(argv, ' ');
    path = find_path(cmd[0], envp);
    if (!path)
    {
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        error();
    }
    if (execve(path, cmd, envp) == -1)
        error();
}