#include "get_next_line.h"

size_t BUFFER_SIZE = 16;

char *get_next_line(int fd)
{
	static t_list *_buffers;
	t_list *current_fd;
	char *line;
	int bytes_total;

	if (fd < 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	line[0] = '\0';
	current_fd = handle_fd(&_buffers, fd);
	bytes_total = current_fd->bytes_read;
	handle_buffer(&line, current_fd, &bytes_total, fd);
	grab_data(&line, current_fd, &bytes_total, fd);
	if (check_for_newline(line, bytes_total) >= 0)
	{
		line[check_for_newline(line, bytes_total) + 1] = '\0';
		int remaining = current_fd->bytes_read - (check_for_newline(current_fd->buffer, current_fd->bytes_read) + 1);
		if (remaining > 0)
			ft_memmove(current_fd->buffer, &current_fd->buffer[check_for_newline(current_fd->buffer, current_fd->bytes_read) + 1], remaining);
		current_fd->bytes_read = remaining;
	}
	else
		free_buffer(&_buffers, fd);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

void grab_data(char **line, t_list *current_fd, int *bytes_total, int fd)
{
	while (check_for_newline(*line, *bytes_total) < 0 && ((current_fd->bytes_read = read(fd, current_fd->buffer, BUFFER_SIZE)) > 0))
	{
		*bytes_total += current_fd->bytes_read;
		line_resize(line, *bytes_total - current_fd->bytes_read, *bytes_total + 1);
		ft_memcpy(&(*line)[*bytes_total - current_fd->bytes_read], current_fd->buffer, current_fd->bytes_read);
		(*line)[*bytes_total] = '\0';
	}
}

void handle_buffer(char **line, t_list *current_fd, int *bytes_total, int fd)
{
	if (current_fd->buffer[0] == '\0')
	{
		*bytes_total += current_fd->bytes_read = read(fd, current_fd->buffer, BUFFER_SIZE);
		ft_memcpy(*line, current_fd->buffer, *bytes_total);
		(*line)[*bytes_total] = '\0';
	}
	else
	{
		ft_memcpy(*line, current_fd->buffer, *bytes_total);
		(*line)[*bytes_total] = '\0';
	}
}

t_list *handle_fd(t_list **list, int fd)
{
	t_list *p;

	p = *list;
	while (p != NULL)
	{
		if (p->fd == fd)
			return (p);
		p = p->next;
	}
	return (add_fd_back(list, fd));
}

t_list *add_fd_back(t_list **list, int fd)
{
	t_list *node;
	t_list *p;

	p = *list;
	node = malloc(sizeof(t_list));
	node->buffer = malloc(BUFFER_SIZE);
	node->buffer[0] = '\0';
	node->bytes_read = 0;
	node->fd = fd;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return (node);
	}
	while (p->next != NULL)
		p = p->next;
	p->next = node;
	return (node);
}
