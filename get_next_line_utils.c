/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:29 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/19 20:25:04 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size !=0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_bufferlinejoin(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	size_t	i;
	char	*res;

	line_len = ft_strlen(line);
	buffer_len = ft_strlen(buffer);
	buffer = ft_calloc(line_len + buffer_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		res[i] = line[i];
		i++;
	}
	while (i < line_len + buffer_len || res[i - 1] == '\n')
	{
		res[i] = buffer[i - line_len];
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

int	ft_strchr(char *s, int c)
{
	while(*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}