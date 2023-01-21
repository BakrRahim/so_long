/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <brahim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:32:52 by brahim            #+#    #+#             */
/*   Updated: 2023/01/20 21:05:44 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_cat(int fd, char *left_line)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	if (BUFFER_SIZE == 2147483647)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(left_line, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(left_line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		left_line = ft_strjoin(left_line, buffer);
	}
	free(buffer);
	return (left_line);
}

char	*oneline(char	*left_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!left_line[i])
		return (NULL);
	while (left_line[i] && left_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left_line[i] && left_line[i] != '\n')
	{
		line[i] = left_line[i];
		i++;
	}
	if (left_line[i] == '\n')
	{
		line[i] = left_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*nextline(char	*left_line)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	next = NULL;
	while (left_line[i] && left_line[i] != '\n')
		i++;
	if (!left_line[i])
	{
		free(left_line);
		free(next);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(left_line) - i + 1));
	if (!next)
		return (NULL);
	i++;
	while (left_line[i])
		next[j++] = left_line[i++];
	next[j] = '\0';
	free(left_line);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_printf("Error\n\033[1;31mFile not found !\033[0m\n");
		exit (EXIT_FAILURE);
	}
	left_line = read_and_cat(fd, left_line);
	if (!left_line)
		return (NULL);
	line = oneline(left_line);
	left_line = nextline(left_line);
	return (line);
}
