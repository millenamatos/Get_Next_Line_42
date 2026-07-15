#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("tests/files/basic.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening the file.\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        printf ("-----------------\n");
        free(line);
    }
    close (fd);
    return(0);
}