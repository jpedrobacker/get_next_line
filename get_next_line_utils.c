/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:18 by jbergfel          #+#    #+#             */
/*   Updated: 2023/10/26 19:31:46 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	ft_strchr(const char *str, int c)
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

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		lenstr1;
	int		lenstr2;
	char	*str;

	i = 0;
	lenstr1 = ft_strlen(str1);
	lenstr2 = ft_strlen(str2);
	if (!str1 && !str2)
		return (NULL);
	str = (char *)malloc(lenstr1 + lenstr2 + 1);
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

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}