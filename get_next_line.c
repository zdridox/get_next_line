#include "get_next_line.h"

size_t BUFFER_SIZE = 3;

char *get_next_line(int fd) // wypierdala sie jak wchodzi w while loop czyli zawsze jak jedno przeczytanie do buffera nie czyta calego pliku naraz
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

	while (check_for_newline(line, bytes_total) < 0 && (bytes_read = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		bytes_total += bytes_read;
		line_resize(&line, bytes_total - bytes_read, bytes_total + 1);
		ft_memcpy(&line[bytes_total - bytes_read], buffer, bytes_read);
		line[bytes_total] = '\0';
	}

	if (line[0] != '\0')
	{
		int nl_pos = check_for_newline(line, bytes_total);
		if (nl_pos >= 0)
		{
			line[nl_pos + 1] = '\0';
			ft_memmove(buffer, buffer + nl_pos + 1, bytes_total - (nl_pos + 1));
			bytes_read -= ft_strlen(line);
		}
	}
	else
	{
		return (NULL);
	}
	return (line);
}
