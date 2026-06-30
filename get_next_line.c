#include "get_next_line.h"

static char *update_stash(char *stash)//guarda o resto pra proxima chamada
{
    int i;
    int j;
    char *new_stash;

    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\0' || stash[++i] == '\0')
        return (free(stash), NULL);
    new_stash = malloc(ft_strlen(stash + i) + 1);
    if (!new_stash)
        return (free(stash), NULL);
    j = 0;
    while(stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return(new_stash);
}

static char *get_line(char *stash) //separa a linha que será retornada
{
    char *line;
    int i;

    i = 0;
    if (!stash || !stash[0])
        return (NULL);
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    line = malloc(i + 2);
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        line[i] = stash[i++];
    if (stash[i] == '\n')
    {
        line[i] = stash[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char *read_to_stash(int fd, char *stash, char *buffer) //junta texto até ter uma linha completa
{
    int bytes_read; //guarda QUANTIDADE de bytes que o read conseguiu ler

    while (!ft_strchr(stash, '\n')) // Enquanto ainda não existe uma linha completa no stash
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE); //coloca os caracteres no buffer e a qntd no bytes_read
        if (bytes_read == -1) //erro de leitura:
        {
            free(stash); //libera o acumulado e retorna null
            stash = NULL;
            return (NULL);
        }
        if (bytes_read == 0)//EOF: não tem mais nada pra ler
            break ;
        buffer[bytes_read] = '\0'; //torna o buffer uma str valida pra finalizar
        stash = ft_strjoin(stash, buffer); //pega o que ja existia em stash e adiciona o pedaço novo de buffer
    }
    return (stash); //retorna o texto acumulado
}

char *get_next_line(int fd) //função principal
{
  static char *stash; //guarda tudo - variavel estática
  char *buffer; // variavel temporaria pra fazer leitura
  char *line;
  
  if (fd < 0 || BUFFER_SIZE <= 0) //valida o fd e o buffer_size
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1); //espaço pra guardar o que for lido
    if (!buffer)
        return (NULL);
    stash = read_to_stash(fd, stash, buffer);
    free(buffer);
    if (!stash)
        return (NULL);
    line = get_line(stash);
    stash = update_stash(stash);
    return (line);
}