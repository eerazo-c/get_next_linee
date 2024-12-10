#include "get_next_line_bonus.h"

int	main(void)
{

	char	*line;
	char	*line1;
	char	*line2;
	int		fd;
	int		ofd;
	int		otfd;

	line = NULL;
	fd = open("file.txt", O_RDONLY);
	ofd = open ("test.txt", O_RDONLY);
	otfd = open ("test1.txt", O_RDONLY);
	line = get_next_line(fd);
	line1 = get_next_line(ofd);
	line2 = get_next_line(otfd);
	while (line && line1 && line2)
	{

		printf("%s", line);
		printf("%s", line1);
		printf("%s", line2);
		free(line);
		free(line1);
		free(line2);
		line = get_next_line(fd);
		line1 = get_next_line(ofd);
		line2 = get_next_line(otfd);
	}
	close(fd);
	return (0);
}
