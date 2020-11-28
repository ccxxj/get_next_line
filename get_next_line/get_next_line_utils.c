/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:18:42 by xxu           #+#    #+#                 */
/*   Updated: 2020/11/28 15:12:31 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned long	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i < start)
		len = 0;
	if (start < i && start + len > i)
		len = i - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
    sub[len] = '\0';
	i = 0;
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}

void	ft_bzero(void *str, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
		n--;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = (char *)malloc((i + j + 1) * sizeof(char));
	if (!join)
		return (NULL);
    join[i + j] = '\0';
	while (j > 0)
	{
		join[i + j - 1] = s2[j - 1];
		j--;
	}
	while (i > 0)
	{
		join[i - 1] = s1[i - 1];
		i--;
	}
	return (join);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = ft_strlen(s1);
	i = 0;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
