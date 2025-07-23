/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:24:36 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/23 14:51:30 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_stash *get_stash(const t_stash *stash_array, int fd)
{
	while (stash_array)
	{
		if(stash_array->fd == fd)
			return ((t_stash *) stash_array);
		stash_array = stash_array->next;
	}
	return (NULL);
}

static t_stash *add_stash(t_stash **stash_array, int fd)
{
	t_stash *aux_stash;
	t_stash *new_stash;

	new_stash = (t_stash *) malloc(sizeof(t_stash));
	if (!new_stash)
		return (NULL);
	aux_stash = *stash_array;
	new_stash->fd = fd;
	new_stash->next = NULL;
	new_stash->content = ft_strdup("");
	if (!new_stash->content)
	{
		free(new_stash);
		return (NULL);
	}
	if(!aux_stash)
	{
		*stash_array = new_stash;
		return ((t_stash *) *stash_array);
	}
	while (aux_stash->next)
		aux_stash = aux_stash->next;
	aux_stash->next = new_stash;
	return (aux_stash->next);
}

static void remove_stash(t_stash **stash_array, int fd)
{
	t_stash *current_stash_array;
	t_stash *last;

	if (!*stash_array)
		return ;
	current_stash_array = *stash_array;
	if (current_stash_array->fd == fd)
	{
		if (current_stash_array->content)
			free(current_stash_array->content);
		*stash_array = (*stash_array)->next;
		free(current_stash_array);
		return ;
	}
	while (current_stash_array && current_stash_array->fd != fd)
	{
		last = current_stash_array;
		current_stash_array = current_stash_array->next;
	}
	if (!current_stash_array)
		return ;
	if (current_stash_array->content)
		free(current_stash_array->content);
	last->next = current_stash_array->next;
	free(current_stash_array);
}

static int get_content(t_stash **stash, char **buffer, char **content_stash)
{
	ssize_t			size_buffer;
	char			*to_free;
	
	*buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char)); 
	size_buffer = 1;
	while (size_buffer)
	{
		size_buffer = read((*stash)->fd, *buffer, BUFFER_SIZE);
		(*buffer)[size_buffer] = '\0';
		to_free = (*stash)->content;
		(*stash)->content = ft_strjoin((*stash)->content, *buffer);
		if (!(*stash)->content)
		{
			free(*buffer);
			return (1);
		}
		free(to_free);
		*content_stash = get_newline_content(stash);
		if (*content_stash)
		{
			free(*buffer);
			return (1);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_stash	*stash_array;
	t_stash			*stash;
	char			*content_stash;

	stash = get_stash(stash_array, fd);
	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);	
	if (!stash)
		stash = add_stash(&stash_array, fd);
	content_stash = get_newline_content(&stash);
	if (content_stash)
		return (content_stash);
	if (get_content(&stash, &buffer, &content_stash))
		return (content_stash);
	free(buffer);
	if (!stash->content[0])
		return (NULL);
	content_stash = ft_strdup(stash->content);
	remove_stash(&stash_array, fd);
	return (content_stash);
}
