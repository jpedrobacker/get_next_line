#include "get_next_line_bonus.h"

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*my_strchr(const char *str, int c)
{
	int		i;
	char	*stri;

	stri = (char *)str;
	i = 0;
	while(stri[i] != c)
	{
		if (stri[i] == '\0')
			return (NULL);
		i++;
	}
	return (stri + i);
}

char	*my_strdup(const char *src)
{
	int		j;
	char	*dst;

	j = 0;
	dst = malloc(my_strlen(src) + 1);
	if (!dst)
		return (0);
	while (src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*my_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		lenstr1;
	int		lenstr2;
	char	*str;

	i = 0;
	lenstr1 = my_strlen(str1);
	lenstr2 = my_strlen(str2);
	if (!str1)
		return (my_strdup(""));
	if (!str1 && !str2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (lenstr1 + lenstr2 + 1));
	if (!str)
		return (NULL);
	while (i < lenstr1 || i < lenstr2)
	{
		if (i < lenstr1)
			str[i] = str1[i];
		if (i < lenstr2)
			str[i + lenstr1] = str2[i];
		i++;
	}
	str[lenstr1 + lenstr2] = '\0';
	return (str);
}

char	*my_substr(const char *src, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	dst = (char *)malloc(sizeof(*src) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (i >= start && j < len)
		{
			dst[j] = src[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
