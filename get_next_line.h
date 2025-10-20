#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

char *get_next_line(int fd);
int check_for_newline(char *buff, int size);
void line_resize(char **line, int size, int new_size);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);