/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:25:12 by aalhamel          #+#    #+#             */
/*   Updated: 2022/02/23 19:42:51 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_helper(char *store, int fd)
{
	int		siz;
	char	ab[BUFFER_SIZE + 1];

	siz = 1;
	while (siz != 0 && !ft_strchr(store, '\n'))
	{
		siz = read(fd, ab, BUFFER_SIZE);
		if (siz < 0)
			return (NULL);
		ab[siz] = '\0';
		store = ft_strjoin(store, ab);
	}
	return (store);
}

char	*ft_get_after_nl(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	while (store[i] != '\n' && store[i])
		i++;
	if (!store[i])
	{
		free (store);
		return (NULL);
	}
	new_store = malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_store)
		return (NULL);
	i++;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = 0;
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*store;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	store = gnl_helper(store, fd);
	if (!store)
	{
		free(store);
		return (NULL);
	}
	res = ft_strdup(store);
	store = ft_get_after_nl(store);
	return (res);
}
