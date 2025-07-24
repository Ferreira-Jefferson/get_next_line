/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:35:26 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/24 15:04:26 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"
#include <unistd.h>

void test_2(char *stash, char *sstash)
{
	
	free(sstash);
	stash[1] = 'B';
}

void test(char *stash, char *sstash)
{
	test_2(stash, sstash);
}
int	main(void)
{
	printf("OPEN_MAX = %ld\n", sysconf(_SC_OPEN_MAX));
	
	int fd = open("file.txt", O_RDONLY);
	int fd2 = open("file copy.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("1[%s]\n", line);
	free(line);
	line = get_next_line(fd);
	printf("1[%s]\n", line);
	free(line);
	
	printf("\n\n");
	line = get_next_line(fd2);
	printf("2[%s]\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("2[%s]\n", line);
	free(line);

	close(fd);
	return (0);
}
