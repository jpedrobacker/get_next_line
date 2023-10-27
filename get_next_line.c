/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:26 by jbergfel          #+#    #+#             */
/*   Updated: 2023/10/26 19:53:25 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *backup)
{
	char	*buffer;
	int		readb;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readb = 1;
	while (readb > 0 && !ft_strchr(backup, '\n'))
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb < 0)
			break;
		buffer[readb] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	if (readb < 0)
		return (NULL);
	else
		return (backup);
}

static char	*get_line(char *backup)
{
	char	*line;
	size_t	size;

	if (!*backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, size);
	if (backup[size] == '\n')
		line[size++] == '\n';
	line[size] = '\0';
	return (line);
}

char	*remove_line(char *backup)
{
	//remove a linha lida
}

char	*get_next_line(int fd)
{
	static char		*lines;
	char			*read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	read = read_file(fd, read);
	if (!read)
		return (NULL);
	lines = get_line(read);
	return (read);
}
