#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd, fd2;
    fd = open("get_next_line.c", O_RDONLY);
    fd2 = open("get_next_line_utils.c", O_RDONLY);
    char *line = get_next_line(fd);
    char *line2 = get_next_line(fd2);
    while (line2 != NULL)
    {
        printf("%s", line2);
        free(line2);
        line2 = get_next_line(fd2);
    }
    printf("\n---\n");
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    close(fd2);
    printf("\n---\n");
    fd = open("file.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    char *str;
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd2);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd2);
    printf("%s", str);
    free(str);
    int fd3 = open("get_next_line.c", O_RDONLY);
    char *linex = get_next_line(fd3);
    while(linex != NULL) {
        printf("%s", linex);
        free(linex);
        linex = get_next_line(fd3);
    }
    close(fd3);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd2);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd2);
    printf("%s", str);
    free(str);
    close(fd);
    close(fd2);
    printf("%s", get_next_line(-1));
    // printf("%s", get_next_line(0));
    return 0;
}