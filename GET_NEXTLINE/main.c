#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test1.txt", O_RDONLY);
	fd3 = open("tests/test2.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd1);
		printf("line 1 : %s\n", line);
		free(line);
		line = get_next_line(fd2);
		printf("line 2 : %s\n", line);
		free(line);
		line = get_next_line(fd3);
		printf("line 3 : %s\n", line);
		free(line);
		if (line == NULL)
			break;	
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}