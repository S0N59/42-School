/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:23:18 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/15 12:24:41 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	child1(t_pipex pipex, char **av, char **envp);
void	child2(t_pipex pipex, char **av, char **envp);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
char	*ft_strchr(const char *s, int c);
void	print_error(char *str);
char	*search_command(char **path, char *cmd);
char	**get_path(char **envp);
void	get_file(t_pipex *pipex, char **av, int ac);

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif
