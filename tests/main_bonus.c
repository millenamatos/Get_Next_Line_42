#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("tests/basic.txt", O_RDONLY);
	fd2 = open("tests/empty_lines.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		printf("Erro ao abrir os arquivos.\n");
		return (1);
	}

	printf("Primeira linha do basic.txt: \n");
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	printf("\nPrimeira linha do empty_lines.txt:\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	printf("\nSegunda linha do empty_lines.txt:\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	printf("\nTerceira linha do empty_lines.txt:\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

    printf("\nSegunda linha do basic.txt:\n");
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	close(fd1);
	close(fd2);
	return (0);
}