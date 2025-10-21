#include "get_next_line.h"
#include <stdio.h>

int main()
{
    /*
    char str1[] = "adasdasda";
    char *str2 = malloc(5);
    str2[0] = 'a';
    str2[1] = 'b';
    str2[2] = '\n';
    str2[3] = 'c';
    str2[4] = '\0';

    printf("str1: '%s' out: %d\n", str1, check_for_newline(str1, 10));
    printf("str2: '%s' out: %d\n", str2, check_for_newline(str2, 5));

    int fd = open("file.txt", O_RDONLY);
    //printf("%s", get_next_line(fd));
    char *str3 = malloc(20);
    char str4[] = "dupa";
    ft_memcpy(str3, "marek", 6);
    my_strcat(str3, str4, ft_strlen(str4) + 1);
    printf("%s\n", str3);
    */
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