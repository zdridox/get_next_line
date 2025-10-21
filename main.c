#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    return 0;
}