#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

int main(void)
{
	int		fd;
	char	*str;
	char	*path;

	path = "text.txt";
	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}
