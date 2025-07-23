/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:48:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/23 14:52:10 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	while (s1[i])
		i++ ;
	dest = (char *) malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_s;
	char	*sub;

	if (!s)
		return (NULL);
	size_s = 0;
	while (s[size_s])
		size_s++ ;
	if (start > size_s)
		return (ft_strdup(""));
	if (start + len > size_s)
		len = size_s - start;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
		i++ ;
	j = 0;
	while (s2[j])
		j++ ;
	res = (char *) malloc((i + j + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

size_t get_newline(char *content)
{
	int	count;

	count = 0;
	while (content && *content)
	{
		count++;
		if (*content == '\n')
			return (count);
		content++;
	}
	return (0);	
}

char *get_newline_content(t_stash **stash)
{
	size_t			pos_newline;
	char			*content_stash;
	char			*to_free;
	t_stash			*aux_stash;
	size_t			size_content;

	aux_stash = *stash;
	pos_newline = get_newline(aux_stash->content);
	if (pos_newline <= 0)
		return (NULL);
	size_content = 0;
	while(aux_stash->content[size_content])
		size_content++;
	if (size_content == pos_newline)
	{
		content_stash = aux_stash->content;
		aux_stash->content = ft_strdup("");
		return (content_stash);
	}
	to_free = aux_stash->content;
	aux_stash->content = ft_substr(aux_stash->content, pos_newline, size_content - pos_newline);
	content_stash = ft_substr(to_free, 0, pos_newline);
	free(to_free);
	return (content_stash);	
}
