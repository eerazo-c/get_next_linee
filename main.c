#include "get_next_line_bonus.h"

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
