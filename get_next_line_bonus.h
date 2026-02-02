/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:45:32 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/16 15:45:34 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*buffer;
	int				bytes_read;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					check_for_newline(char *buff, int size);
void				line_resize(char **line, int size, int new_size);
void				*ft_memmove(void *dest, const void *src, size_t n);
t_list				*handle_fd(t_list **list, int fd);
t_list				*add_fd_back(t_list **list, int fd);
void				free_buffer(t_list **buffers, int fd);
void				grab_data(char **line, t_list *current_fd, int *bytes_total,
						int fd);
void				load_buffer(char **line, t_list *current_fd,
						int *bytes_total, int fd);
void				handle_buffer(char **line, t_list *current_fd,
						int *bytes_total, t_list **_buffers);
#endif
