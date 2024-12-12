/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:04:43 by elerazo-          #+#    #+#             */
/*   Updated: 2024/12/11 17:31:43 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
