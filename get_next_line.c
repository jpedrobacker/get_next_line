/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:26 by jbergfel          #+#    #+#             */
/*   Updated: 2023/10/26 19:53:25 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		byte;
	char	*str_buffer;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str_buffer)
		return (NULL);
}

/*
int main(void)
{
	int		fd;
	char	*str;
	char	*path;
	int		i;

	path = "text.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 6)
	{
		str = get_next_line(fd);
		printf("fd: %i, %s\n", fd, str);
		i++;
	}
	close(fd);
	return (0);
}
*/
