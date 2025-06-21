/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:28:06 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/27 11:28:08 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_func(char *line, int fd)
{
	char	*buff;
	int		k;

	k = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!ft_strchr(line, '\n') && k != 0)
	{
		k = read(fd, buff, BUFFER_SIZE);
		if (k == -1)
		{
			free (buff);
			return (0);
		}
		buff[k] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_line(char *stline)
{
	char	*line;
	int		i;

	i = 0;
	if (stline[i] == '\0')
		return (0);
	while (stline[i] && stline[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stline[i] && stline[i] != '\n')
	{
		line[i] = stline[i];
		i++;
	}
	if (stline[i] == '\n')
	{
		line[i] = stline[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*trim(char *stline)
{
	char	*line;
	int		befn;
	int		aftn;

	befn = 0;
	aftn = 0;
	while (stline[befn] && stline[befn] != '\n')
		befn++;
	if (!stline[befn])
	{
		free(stline);
		return (0);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(stline) - befn + 1));
	if (!line)
		return (0);
	befn++;
	while (stline[befn])
		line[aftn++] = stline[befn++];
	line[aftn] = 0;
	free (stline);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stline = read_func(stline, fd);
	if (!stline)
		return (0);
	line = get_line (stline);
	stline = trim (stline);
	return (line);
}
