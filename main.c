/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:35:26 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 14:11:10 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		printf("[%s]", line);
		free(line);
	}
	close(fd);
	return (0);
}