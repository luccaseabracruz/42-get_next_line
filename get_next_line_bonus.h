/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:25:23 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/21 18:25:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

void	*get_next_line(int fd);
int		ft_findlinebreak(char	*str);
char	*ft_bufferlinejoin_bonus(char *line, char *buffer);
char	*ft_clean_buffer_bonus(char *buffer);

#endif