/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:19:01 by lginer-m          #+#    #+#             */
/*   Updated: 2024/09/21 13:37:31 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (save)
		{
			free(save);
			save = NULL;
		}
	}
	if (save == NULL)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	save = (gnl_read_txt(fd, save));
	if (save == NULL)
		return (NULL);
	line = gnl_extract_line(save);
	save = gnl_the_rest(save);
	return (line);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_read_txt(int fd, char	*save)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[0] = '\0';
	while (bytes_read > 0 && gnl_strchr(buffer, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = gnl_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*gnl_extract_line(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		line[j++] = save[i++];
	if (save[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*gnl_the_rest(char *save)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	i++;
	rest = (char *)malloc(sizeof(char) * (gnl_strlen(save + i) + 1));
	if (!rest)
		return (NULL);
	while (save[i])
		rest[j++] = save[i++];
	rest[j] = '\0';
	free(save);
	return (rest);
}
