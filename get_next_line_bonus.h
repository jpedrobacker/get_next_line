#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *src, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif