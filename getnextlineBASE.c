#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n);
void line_resize(char **line, int bytes_read);
char *get_next_line(int fd);

char *get_next_line(int fd)
{
	char *line;
	char buff[1];
	int bytes_read;
	int bytes;

	bytes_read = 0;
	bytes = 0;
	line = malloc(2);
	bytes_read += read(fd, buff, 1);
	if (bytes_read <= 0)
		return (free(line), NULL);
	ft_memcpy(line, buff, 1);
	while (buff[0] != '\n' && bytes_read > 0 && (bytes = read(fd, buff, 1) > 0))
	{
		bytes_read += bytes;
		line_resize(&line, bytes_read);
		ft_memcpy(&line[bytes_read - 1], buff, 1);
	}
	line[bytes_read] = '\0';
	return (line);
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

void line_resize(char **line, int bytes_read)
{
	char *buff_line;

	buff_line = malloc(bytes_read);
	ft_memcpy(buff_line, *line, (size_t)bytes_read);
	free(*line);
	*line = malloc(bytes_read + 1);
	ft_memcpy(*line, buff_line, (size_t)bytes_read);
	free(buff_line);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	int df = open("text2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(df));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(df));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(df));
	// printf("%s", get_next_line(0)); // works but printf sucks
	return 0;
}
