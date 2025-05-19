/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:05:35 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/19 18:58:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// test_join();
}

void	test_join(void)
{
	char	*s1 = strdup("Lucca ");
	char	*s2 = strdup("Cruz");
	char	*res = ft_strjoinfree(s1, s2);

	printf("%s\n", res);
	free(res);
}