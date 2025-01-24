#include "get_next_line.h"

char	*my_free(char *to_free)
{
	free(to_free);
	to_free = NULL;
	return (to_free);
}

char	*read_file(int fd, char *buffer, char *extra)
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
			extra = my_strdup("");
		temp = extra;
		extra = my_strjoin(temp, buffer);
		temp = my_free(temp);
		if (my_strchr(buffer, '\n'))
			break;
	}
	return (extra);
}

char	*extract_line(char *line)
{
	size_t	i;
	char	*extra;

	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	extra = my_substr(line, i + 1, my_strlen(line) - i);
	if (*extra == '\0')
		extra = my_free(extra);
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
	buffer = my_free(buffer);
	if (!line)
		return (NULL);
	extra = extract_line(line);
	return (line);
}
