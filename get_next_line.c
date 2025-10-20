#include "get_next_line.h"

size_t BUFFER_SIZE = 4;

char *get_next_line(int fd)
{
	char *line;
	static char *buffer;
	int bytes_total;
	static int bytes_read;

	if (!bytes_read)
		bytes_read = 0;
	bytes_total = bytes_read;
	line = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE);
		bytes_total += bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_memcpy(line, buffer, bytes_total);
		line[bytes_total] = '\0';
	}
	else
	{
		ft_memcpy(line, buffer, bytes_read);
		line[bytes_read] = '\0';
	}

	while (check_for_newline(line, bytes_total) < 0 && ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		bytes_total += bytes_read;
		line_resize(&line, bytes_total - bytes_read, bytes_total + 1);
		ft_memcpy(&line[bytes_total - bytes_read], buffer, bytes_read);
		line[bytes_total] = '\0';
	}

	if (check_for_newline(line, bytes_total) >= 0)
	{
		line[check_for_newline(line, bytes_total) + 1] = '\0';

		int remaining = bytes_read - (check_for_newline(buffer, bytes_read) + 1);
		if (remaining > 0)
			ft_memmove(buffer, &buffer[check_for_newline(buffer, bytes_read) + 1], remaining);
		bytes_read = remaining;
	}
	else
	{
		if (line[0] == '\0')
			return (NULL);
		bytes_read = 0;
	}
	return (line);
}