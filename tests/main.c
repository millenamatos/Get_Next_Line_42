#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("tests/empty_lines.txt", O_RDONLY); //abre o arquivo apenas para leitura
    if (fd == -1)
    {
        printf("Erro ao abrir o arquivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL) //chama gnl repetidamente até retornar null, a cada chamada ela retorna uma linha
    {
        printf("%s", line);
        printf ("-----------------\n");
        free(line);
    }
    close (fd); //fecha o arquivo após finalizar a leitura
    return(0);
}