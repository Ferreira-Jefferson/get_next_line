/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:48:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/20 13:18:18 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;
	
	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	char	*aux_s;
	size_t	size;

	if (!s)
		return (NULL);
	aux_s = (char *) s;
	size = 0;
	while (*s++)
		size++;
	new_str = (char *) malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	while (size--)
		new_str[size] = aux_s[size];
	return (new_str);
}
