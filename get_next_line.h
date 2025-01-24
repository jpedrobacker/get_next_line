#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*my_strchr(const char *str, int c);
char	*my_strjoin(const char *str1, const char *str2);
char	*my_strdup(const char *src);
char	*my_substr(const char *src, unsigned int start, size_t len);
size_t	my_strlen(const char *s);

#endif
