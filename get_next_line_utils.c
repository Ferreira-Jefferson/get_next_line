/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:48:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 13:54:12 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux_s1;
	char	*join = NULL;
	size_t	size_join;
	size_t	i;

	if (!s1)
		return (NULL);
	aux_s1 = (char *) s1;
	if (!s2)
		return (aux_s1);
	size_join = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *) malloc(size_join * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';	
	return (join);
}
