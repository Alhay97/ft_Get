/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:25:04 by aalhamel          #+#    #+#             */
/*   Updated: 2022/02/23 19:44:59 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
	}
	j = 0;
	free (s1);
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	i++;
	ptr = malloc((i * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	j;

	i = 0;
	j = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s != NULL && s[i] == j)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
