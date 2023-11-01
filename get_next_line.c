/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:26 by jbergfel          #+#    #+#             */
/*   Updated: 2023/11/01 17:28:39 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *buffer, char *extra)
{
	int		read_file;
	char	*temp;

	read_file = 1;
	while (read_file != '\0')
	{
		read_file = read(fd, buffer, BUFFER_SIZE);
		if (read_file == -1)
			return (NULL);
		else if (read_file == 0)
			break;
		buffer[read_file] = '\0';
		if (!extra)
			extra = ft_strdup("");
		temp = extra;
		extra = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (extra);
}

static char	*extract_line(char *line)
{
	size_t	i;
	char	*extra;

	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' && line[1] == '\0')
		return (NULL);
	extra = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*extra == '\0')
	{
		free(extra);
		extra = NULL;
	}
	line[i + 1] = '\0';
	return (extra);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_file(fd, buffer, extra);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	extra = extract_line(line);
	return (line);
}
