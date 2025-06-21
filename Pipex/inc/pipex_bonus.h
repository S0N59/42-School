/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:13:24 by nkostany          #+#    #+#             */
/*   Updated: 2023/06/19 14:13:26 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void    error(void);
char    *find_path(char *cmd, char **envp);
void    execute(char *argv, char **envp);

int    open_file(char *argv, int i);
void    usage(void);
void    here_doc(char *limiter, int argc);
void    pipe_process(int i, int argc, char **argv, char **envp);
void    wait_process(int pipe_fd[2], pid_t *child_pids, int child_count);
pid_t    child_process(int pipe_fd[2], char argv[], char **envp);
char	*search_command(char **path, char *cmd);

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *dst, char *src);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	readf(char *line, int fd);
char	*trim(char *stline);
char	*get_line(char *stline);
#endif
