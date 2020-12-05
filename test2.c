/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:43:56 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/12/05 17:07:01 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int		check_n(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	check_initialization(t_store *store)
{
	if (!store->initialization)
	{
		store->rest_line = NULL;
		store->index_n = 0;
		store->flag = 0;
		store->initialization = 1;
	}
}

int		check_rest_line(char **line, char *str, int n, t_store *store)
{
	int len;

	if (str)
	{
		if (n > -1)
		{
			line[0] = ft_strjoin(line[0], ft_substr(str, 0, n));
			if (!line[0])
				return (-1);
			len = ft_strlen(str);
			store->rest_line = ft_substr(str, n + 1, len - n - 1);
			if (!store->rest_line)
				return (-1);
			store->index_n = check_n(store->rest_line);
			return (1);
		}
		else
			line[0] = ft_strjoin(line[0], ft_strdup(str));
	}
	return (0);
}

int		ft_read(int fd, char *buf, char **line, t_store *store)
{
	while (1)
	{
		store->result = read(fd, buf, BUFFER_SIZE);
		if (store->result == -1)
			return (-1);
		store->flag = store->result < BUFFER_SIZE ? 1 : 0;
		store->i = check_rest_line(line, buf, check_n(buf), store);
		if (store->i == -1)
		{
			free(buf);
			return (-1);
		}
		if (store->flag == 1 && (store->rest_line[0] == '\0' || store->i == 0))
		{
			free(buf);
			return (0);
		}
		else if (store->i == 0)
			ft_bzero(buf, BUFFER_SIZE + 1);
		else
		{
			free(buf);
			return (1);
		}
	}
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static	t_store	store;

	check_initialization(&store);
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	ft_bzero(buf, BUFFER_SIZE + 1);
	line[0] = "\0";
	store.i = check_rest_line(line, store.rest_line, store.index_n, &store);
	if (store.i == -1)
	{
		free(buf);
		return (-1);
	}
	if (store.flag == 1 && (store.rest_line[0] == '\0' || store.i == 0))
		return (0);
	if (store.i == 1)
		return (1);
	return (ft_read(fd, buf, line, &store));
}
