/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:08 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/19 20:26:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//validate input
//loop (join and free until \n or \0)

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_bufferjoin(NULL, buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_bufferlinejoin(line, buffer);
	}
	// clean buffer letting just chars after \n
	return (line);
}
