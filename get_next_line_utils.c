#include "get_next_line.h"

int check_for_newline(char *buff, int size) {
	int i;

	i = 0;
	while (i < size) {
		if(buff[i] == '\n')
			return(i);
		if(buff[i] == '\0')
			return(-2);
		i++;
	}
	return(-1);
}

void line_resize(char **line, int size, int new_size)
{
	char *buff_line;

	buff_line = malloc(size);
	ft_memcpy(buff_line, *line, (size_t)size);
	free(*line);
	*line = malloc(new_size);
	ft_memcpy(*line, buff_line, (size_t)size);
	*line[size] = '\0';
	free(buff_line);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void my_strcat(char *dest, char *src, int n) {
	int dest_len;
	int i;

	i = 0;
	dest_len = ft_strlen(dest);
    while (i < n) {
		dest[dest_len + i] = src[i];
		i++;
	}   
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
