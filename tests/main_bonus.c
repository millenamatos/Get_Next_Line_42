#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("arquivo1.txt", O_RDONLY);
	fd2 = open("arquivo2.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		printf("Erro ao abrir os arquivos.\n");
		return (1);
	}

	printf("=== Primeira linha do arquivo 1 ===\n");
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	printf("\n=== Primeira linha do arquivo 2 ===\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	printf("\n=== Segunda linha do arquivo 2 ===\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	printf("\n=== Terceira linha do arquivo 2 ===\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

    printf("\n=== Segunda linha do arquivo 1 ===\n");
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

    printf("\n=== Quinta linha do arquivo 2 ===\n");
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	close(fd1);
	close(fd2);
	return (0);
}