#include "get_next_line.h"

int main(void)
{
	int fd;
	char buf[256];
	int chars_read;

	fd = open("text.txt", O_RDONLY);
	while (chars_read = read(fd, buf, 25))
	{
		buf[chars_read] = '\0';
		printf("buf-> %s\n",buf);
	}
}
