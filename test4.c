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
	if (ft_strlen(ptr) >= size)
		return (ptr);
	newptr = (char *)malloc((size) * sizeof(char));
	while (ptr[i])
	{
		newptr[i] = ptr[i];
		i++;
	}
	newptr[i] = '\0';
	free(ptr);// this is problemetic,
	return (newptr);
}

int		split(char **line, int len, char *str, int n, t_store *store)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (n == -1)
	{
		while (str[i])
		{
			(*line)[len + i] = str[i];
			i++;
		}
		store->rest_line = NULL;
		return (1);
	}
	store->rest_line = ft_realloc(store->rest_line, ft_strlen(str) - n);
	if (!store->rest_line)
		return (-1);
	while (str[i])
	{
		if (i < n)
			(*line)[len + i] = str[i];
		if (i > n)
			store->rest_line[i - n - 1] = str[i];
		i++;
	}
	store->rest_line[i - n -1] = '\0';
	return (1);
}

int		check_rest_line(char **line, char *str, int n, t_store *store)
{
	int	len;
	int	m;
	int	result;

	len = ft_strlen(*line);
	// printf("check\n");
	m = n == -1 ? ft_strlen(str) : n;
	// printf("check\n");
	*line = ft_realloc(*line, len + m + 1);
	// printf("len + m is %d\n", len + m);
	if (!*line)
		return (-1);
	// printf("check\n");
	result = split(line, len, str, n, store);
	// printf("check aaaaa\n");
	if (result == -1)
		return (-1);
	// printf("len + m is second time%d\n", len + m);
	(*line)[len + m] = '\0';
	// printf("ollaaaaa\n");
	if (n > -1)
	{
		store->index_n = check_n(store->rest_line);
		return (1);
	}
	else
		return (0);
}

int		ft_read(int fd, char *buf, char **line, t_store *store)
{
	while (1)
	{
		store->result = read(fd, buf, BUFFER_SIZE);
		if (store->result == -1)//good
			return (-1);
		buf[store->result] = '\0';
		store->flag = store->result < BUFFER_SIZE ? 1 : 0;
		store->i = check_rest_line(line, buf, check_n(buf), store);
		// printf("store i is %d\n", store->i);
		if (check_n(buf) > -1)
			return (1);
		// printf("result1\n");
		if ((store->flag == 1 && check_n(buf) < 0) || store->result == 0)
			return (0);
		// printf("result2\n");
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
		store.index_n = -1;
		store.flag = 0;
		store.initialization = 1;
		store.result = 0;
	}
	*line = (char *)malloc(10);
	(*line)[0] = '\0';
	store.i = check_rest_line(line, store.rest_line, store.index_n, &store);
	if (store.i == -1)
		return (-1);
	if (store.flag == 1 && store.i == 0)
		return (0);
	if (store.i == 1)
		return (1);
	return (ft_read(fd, store.buf, line, &store));
}
