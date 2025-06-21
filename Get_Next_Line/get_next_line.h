/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:31:19 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/30 11:15:36 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*readf(char *line, int fd);
char		*trim(char *stline);
char		*get_line(char *stline);
#endif
