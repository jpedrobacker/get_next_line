#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

int count_path(char **path)
{
	int j = 0;
	int i;

	while(*path)
	{
		i = 0;
		while (path[j][i] != '\0')
		{
			if (path[j][0] == '\0')
				break;
			i++;
		}
		j++;
		path--;
	}
	return (j);
}

int main(void)
{
	int		fd;
	char	*str;
	char	*path[] = {"text.txt", "text_bonus.txt"};
	int i = 0;
	int j;

	j = count_path(path);
	while (i < j)
	{
		fd = open(path[i], O_RDONLY);
		while (1)
		{
			str = get_next_line(fd);
			if (str == NULL)
				break;
			printf("%s", str);
			free(str);
		}
		i++;
	}
	printf("%d", j);
	close(fd);
	return (0);
}
