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
	str = get_next_line(fd);
	printf("fd: %i, %s\n", fd, str);
	close(fd);
	return (0);
}
