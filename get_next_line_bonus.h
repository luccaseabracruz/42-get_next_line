/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:25:23 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/22 16:32:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
void	*ft_calloc_bonus(size_t nmemb, size_t size);
int		ft_findlinebreak(char	*str);
char	*ft_bufferlinejoin_bonus(char *line, char *buffer);
void	ft_clean_buffer_bonus(char *buffer);

#endif