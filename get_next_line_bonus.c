/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:31:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/21 20:15:15 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc_bonus(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer[fd])
			return (NULL);
	}
	line = ft_bufferlinejoin_bonus(NULL, buffer[fd]);
	while (!ft_findlinebreak(buffer[fd]))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0 || buffer[fd][0] == '\0')
		{
			ft_clean_buffer_bonus(buffer[fd]);
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		line = ft_bufferlinejoin_bonus(line, buffer[fd]);
	}
	ft_clean_buffer_bonus(buffer[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	fd = open("get_next_line.h", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }