/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:04:43 by elerazo-          #+#    #+#             */
/*   Updated: 2024/12/09 23:31:33 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_update(char *space)
{
	size_t	len_str;
	char	*new;
	int		i;
	int		j;

	if (space == NULL)
		return (NULL);
	i = 0;
	while (space[i] != '\n' && space[i] != '\0')
		i++;
	if (space[i] == '\0')
		return (ft_clean(&space));
	len_str = ft_strlen(space);
	new = malloc(sizeof(char) * len_str + 1);
	if (!new)
		return (ft_clean(&space));
	j = 0;
	i++;
	while (space[i] != '\0')
		new[j++] = space[i++];
	new[j] = '\0';
	free(space);
	return (new);
}

char	*ft_extract_ln(char *space)
{
	char	*line;
	int		i;
	int		j;

	if (space == NULL)
		return (NULL);
	i = 0;
	while (space[i] != '\n' && space[i] != '\0')
		i++;
	if (space[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = space[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *space)
{
	char	*buffer;
	int		re_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_clean(&space));
	buffer[0] = '\0';
	re_bytes = 1;
	while (re_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		re_bytes = read(fd, buffer, BUFFER_SIZE);
		if (re_bytes == -1)
		{
			free(buffer);
			return (ft_clean(&space));
		}
		if (re_bytes > 0)
		{
			buffer[re_bytes] = '\0';
			space = ft_strjoin(space, buffer);
		}
	}
	free(buffer);
	return (space);
}

char	*get_next_line(int fd)
{
	static char	*space = NULL;
	char		*nx_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(space);
		space = NULL;
		return (NULL);
	}
	space = ft_read(fd, space);
	if (space == NULL)
		return (NULL);
	nx_line = ft_extract_ln(space);
	if (nx_line == NULL)
		return (ft_clean(&space));
	space = ft_update(space);
	if (space == NULL)
	{
		free(nx_line);
		return (NULL);
	}
	return (nx_line);
}

int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
