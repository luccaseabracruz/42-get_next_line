/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:29 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/21 18:29:27 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_bufferlinejoin(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	size_t	i;
	char	*res;

	line_len = ft_linelen(line);
	buffer_len = ft_linelen(buffer);
	res = ft_calloc(line_len + buffer_len + 1, sizeof(char));
	if (!res)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < line_len)
	{
		res[i] = line[i];
		i++;
	}
	i--;
	while (++i < line_len + buffer_len)
		res[i] = buffer[i - line_len];
	free(line);
	return (res);
}

int	ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

void	ft_cleanbuffer(char *buffer)
{
	int		i;
	int		j;

	if (!buffer)
		return ;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	while (buffer[j])
	{
		buffer[j] = '\0';
		j++;
	}
}
