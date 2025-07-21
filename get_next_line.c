/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:24:36 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 17:00:30 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	char	stash[BUFFER_SIZE + 1];

int	ft_populate_stash(int pos, char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[pos])
		stash[i++] = buffer[pos++];
	stash[i] = '\0';
	return (i);
}

int	ft_find_newline(char *buffer)
{
	int	pos;

	pos = 0;
	while (buffer[pos] && buffer[pos] != '\n')
		pos++;
	if (buffer[pos] == '\n')
		pos++;
	return (ft_populate_stash(pos, buffer));
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	int				size_read;
	int				size_stash;
	char			*dinamic_stash;
	char			*to_free;

	dinamic_stash = ft_strdup(stash);
	if (!dinamic_stash)
		return (NULL);
	size_read = 1;
	while (size_read)
	{
		if (stash[0] == '\n')
		{
			ft_populate_stash(1, dinamic_stash);
			dinamic_stash[1] = '\0';
			return (dinamic_stash);
		}
		to_free = dinamic_stash;
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read] = '\0';
		printf("entrou: %d | [%s]\n", size_read, buffer);
		if (size_read <= 0)
		{
			free(to_free);
			return (NULL);
		}
		size_stash = ft_find_newline(buffer);
		if(size_stash != 0)
		{
			buffer[size_read - size_stash] = '\0';
			dinamic_stash = ft_strjoin(dinamic_stash, buffer);
			free(to_free);
			return (dinamic_stash);
		}
		dinamic_stash = ft_strjoin(dinamic_stash, buffer);
		free(to_free);
	}
	free(to_free);
	return (dinamic_stash);
}
