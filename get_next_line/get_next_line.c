/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:31:38 by muokcan           #+#    #+#             */
/*   Updated: 2024/12/19 16:10:41 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*get_buffer(int fd, char *buffer)
{
	int		buff_size;
	char	*temp_buffer;

	temp_buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!temp_buffer)
		return (NULL);
	while (1)
	{
		buff_size = read(fd, temp_buffer, BUFFER_SIZE);
		if (buff_size <= 0)
			return (NULL);
		temp_buffer[buff_size] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break;
	}
	free (temp_buffer);
	return (buffer);
}

static char	*get_line(int fd, char *buffer)
{
	unsigned int	i;
	char			*line;

	if (!buffer || *buffer == '\0')
		buffer = NULL;
	buffer = get_buffer(fd, buffer);
	line = malloc(ft_word_len(buffer) + 1);
	while (*buffer != '\n' && *buffer != '\0')
	{
		*line = *buffer;
		line++;
	}
	*line = '\0';
	free(buffer);
	return (line);
}

char		*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;

	if (!buffer)
		buffer = malloc(1);
	buffer = get_buffer(fd, buffer);
	next_line = malloc(ft_word_len(buffer) + 1); // redundant/changeable (ft_word_len) usage, declare a new 'len' variable.
	next_line = get_line(fd, buffer);
	return (next_line);
}
