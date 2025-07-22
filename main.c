/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:35:26 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/22 15:07:03 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	int fd2 = open("file copy.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("[%s]", line);
	free(line);
	line = get_next_line(fd2);
	printf("[%s]", line);
	free(line);
	line = get_next_line(fd);
	printf("[%s]", line);
	free(line);
		line = get_next_line(fd2);
	printf("[%s]", line);
	free(line);

	close(fd);
	return (0);
}
