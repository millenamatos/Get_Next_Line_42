#include <stdio.h> //printf
#include <stdlib.h> //free
#include <fcntl.h> //open e O_RDONLY
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("teste.txt", O_RDONLY); //abre o arquivo apenas para leitura
    if (fd == -1)
    {
        printf("Erro ao abrir o arquivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL) //chama gnl repetidamente até retornar null, a cada chamada ela retorna uma linha
    {
        printf("[%s]\n", line); //imprime entre [] pra facilitar leitura
        free(line); //libera memória alocada por gnl
    }
    close (fd); //fecha o arquivo após finalizar a leitura
    return(0);
}