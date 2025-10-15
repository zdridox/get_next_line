#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

char *get_next_line(int fd);
int check_for_newline(char *buff, int size);
void line_resize(char **line, int size, int new_size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void *ft_memcpy(void *dest, const void *src, size_t n);
void my_strcat(char *dest, char *src, int n);
void	*ft_memmove(void *dest, const void *src, size_t n);