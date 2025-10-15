#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t BUFFER_SIZE = 42;
	char *line;
	static char *buffer;
	int bytes_total;
	int bytes_read;
	int newline_index;


	bytes_total = ft_strlen(buffer);
	if(!buffer)
		buffer = malloc(BUFFER_SIZE);
	line = malloc(BUFFER_SIZE);
	line[0] = '\0';
	if(buffer)
		ft_memcpy(line, buffer, ft_strlen(buffer));
	while (check_for_newline(line, bytes_total) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		bytes_total += bytes_read;
		line_resize(&line, bytes_total - bytes_read, bytes_total + 1);
		my_strcat(line, buffer, bytes_read);
	}
	line[check_for_newline(line, bytes_total) + 1] = '\0';
	int nl_idx = check_for_newline(buffer, bytes_read);
	ft_memmove(buffer, &buffer[nl_idx + 1], bytes_read - (nl_idx + 1));
	return (line);
}
