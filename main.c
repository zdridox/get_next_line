#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd, fd2;
    fd = open("get_next_line.c", O_RDONLY);
    fd2 = open("get_next_line_utils.c", O_RDONLY);
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
    return 0;
}