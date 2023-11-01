/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:26 by jbergfel          #+#    #+#             */
/*   Updated: 2023/11/01 15:58:09 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *line)
{
	char	*buffer;
	int		readb;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readb = 1;
	while (readb > 0 && !ft_strchr(line, '\n'))
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb < 0)
			break;
		buffer[readb] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	if (readb < 0)
		return (NULL);
	else
		return (line);
}

static char	*get_line(char *line)
{
	char	*text;
	size_t	size;

	if (!*line)
		return (NULL);
	size = 0;
	while (line[size] && line[size] != '\n')
		size++;
	text = (char *)malloc(sizeof(char) * (size + 2));
	if (!text)
		return (NULL);
	ft_strlcpy(text, line, size);
	if (line[size] == '\n')
		text[size++] = '\n';
	text[size] = '\0';
	return (text);
}

static char	*remove_line(char *next_line)
{
	//remove line function
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	next_line = read_file(fd, next_line);
	if (!next_line)
		return (NULL);
	line = get_line(next_line);
	next_line = remove_line(next_line);
	return (line);
}
