#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    printf("\n---\n");
    char *line2 = get_next_line(fd2);
    while (line2 != NULL)
    {
        printf("%s", line2);
        free(line2);
        line2 = get_next_line(fd2);
    }
    close(fd);
    close(fd2);
    return 0;
}