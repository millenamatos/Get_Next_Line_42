#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("teste.txt", O_RDONLY); //abre o arquivo para leitura
    if (fd == -1) //se retornar -1, significa que ocorreu erro (arquivo não existe, sem permissão, etc)
    {
        printf("Erro\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL) //chama gnl repetidamente até retornar null, a cada chamada ela retorna uma linha
    {
        printf("[%s]\n", line); //imprime entre [] pra facilitar leitura
        free(line); //libera memória alocada por gnl
    }
    close (fd); //fecha o arquivo para liberar o fd
    return(0);
}