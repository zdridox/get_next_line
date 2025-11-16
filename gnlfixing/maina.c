/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:00:50 by alusnia           #+#    #+#             */
/*   Updated: 2025/10/22 21:21:44 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int x = 1;
	char *s;
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	open("1", O_RDONLY);
	open("2", O_RDONLY);
	open("3", O_RDONLY);
	while (x < argc)
	{
		s = get_next_line(*argv[x] - '0' + 2);
		if (s)
			printf("%s", s);
		else
			printf("%s\n", s);
		free(s);
		x++;
	}

	x = 3;
	while (x <= 6)
	{
		while (1)
		{
			s = get_next_line(x);
			if (s)
				free(s);
			else
			{
				free(s);
				break;
			}
		}
		x++;
	}
	return (0);
}
