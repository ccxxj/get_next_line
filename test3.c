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

char	*ft_realloc(char *ptr, int size)
{
	char	*newptr;
	int		i;

	i = 0;
	if (!ptr)
	{
		ptr = (char *)malloc((size) * sizeof(char));
		return (ptr);
	}
	newptr = (char *)malloc((size) * sizeof(char));
	while (ptr[i])
	{
		newptr[i] = ptr[i];
		i++;
	}
	newptr[i] = '\0';
	// free(ptr);//figure out why this is causing error, once I try to free, it is telling me nothing to free
	return (newptr);
}

int		check_rest_line(char **line, char *str, int n, t_store *store)
{
	char *temp; //if to many lines, define temp in the gnl function
	
	temp = (char *)malloc((n + 1) * sizeof(char));
	if (!temp)
		return (-1);
	temp[n] = '\0';
	store->rest_line = ft_memccpy(temp, str, 10, store->result);
	if (str && n > -1)
	{
		line[0] = ft_realloc(line[0], ft_strlen(line[0]) + n + 1);
		if (!line[0])
		{
			free(temp);
			return (-1);
		}
		line[0] = ft_strcat(line[0], temp);
		store->index_n = check_n(store->rest_line);
		free(temp);
		return (1);
	}
	else if (str && n == -1)
	{
		line[0] = ft_realloc(line[0], ft_strlen(line[0]) + ft_strlen(str) + 1);
		line[0] = ft_strcat(line[0], str);
		if (!line[0])
			return (-1);
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
		buf[store->result] = '\0';
		store->flag = store->result < BUFFER_SIZE ? 1 : 0;
		store->i = check_rest_line(line, buf, check_n(buf), store);
		if (check_n(buf) > -1)
			return (1);
		if ((store->flag == 1 && check_n(buf) < 0) || store->result == 0)
			return (0);
		if (check_n(buf) == -1)
			ft_bzero(buf, BUFFER_SIZE + 1);
	}
}

int		get_next_line(int fd, char **line)
{
	static	t_store	store;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!store.initialization)
	{
		store.rest_line = NULL;
		store.index_n = 0;
		store.flag = 0;
		store.initialization = 1;
		store.result = 0;
	}
	line[0] = "\0";
	store.i = check_rest_line(line, store.rest_line, store.index_n, &store);
	if (store.i == -1)
		return (-1);
	if (store.flag == 1 && store.i == 0)
		return (0);
	if (store.i == 1)
		return (1);
	return (ft_read(fd, store.buf, line, &store));
}
