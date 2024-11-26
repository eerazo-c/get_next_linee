/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:04:43 by elerazo-          #+#    #+#             */
/*   Updated: 2024/11/26 16:43:43 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read(int fd, char *space)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
}
char *get_next_line(int fd)
{
	static char	*space = NULL;
	char		*nx_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	space = ft_read(fd, space);
	if (space == NULL)
		return (NULL);
	/*nxline = ft_extractln(space);
	if (nxline == NULL)
		return (NULL);*/
	return (space);
}

int main ()
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
