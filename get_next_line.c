/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:14:09 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/12/03 21:35:36 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static  t_store store;
static	int store_initialized = 0;

// (if (!store_initialized)
// {
// 	store->rest_line = NULL;
// 	store->index_n = 0;
// 	store_initialized = 1;
// })

int check_n(char *str)
{
    int i;

	i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return(i);
        i++;
    }
    return (-1);
}

int check_rest_line(char **line, char *str, int n)
{
    int len;

    if (str) // when the rest line exist contains \n
    {        
        if (n > -1) //check later, this is to cpy the before n to line, and rest to the struct rest
        {
            *line = ft_substr(str, 0, n + 1);// +1 is for null terminater
            len = ft_strlen(str);
            store.rest_line = ft_substr(str, n + 1, len - n); // figure out the lenth???? + - 1
            return (1);
        }
        else
            line[store.j] = ft_strdup(str);
    }
    return (0); //if the return is 1, means it pass the \n, no need to read further; else continue read
}


int	get_next_line(int fd, char **line)
{
    int i;
    int result;
    char *buf;

    if (fd == -1 || line == NULL || BUFFER_SIZE == 0)
        return (-1);
	if (!store_initialized)
	{
		store.rest_line = NULL;
		store.index_n = 0;
		store.j = 0;
		store_initialized = 1;
	}
    line[store.j] = "\0";
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (-1);
    ft_bzero(buf, BUFFER_SIZE + 1);
    i = check_rest_line(line, store.rest_line, store.index_n);
    printf("check n i is %d\n", i);
    if (i == 1)
        return (1);
	// buf[BUFFER_SIZE] = '\0';
	// printf("%d\n", result);
    while (1)
    {
        result = read(fd, buf, BUFFER_SIZE);
		printf("result is %d\n", result);
		printf("buf is %s\n", buf);
        if (result == -1)
            return (-1);
        while (result == BUFFER_SIZE && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
        printf("i is %d\n", i);
        if (result == 0)
        {
            line[store.j] = ft_strjoin(line[store.j], buf);
            free(buf);
            return (0);
        }
        else if (i < result)
        {
            line[store.j] = ft_strjoin(line[store.j], ft_substr(buf, 0, i));
            store.rest_line = ft_substr(buf, i + 1, BUFFER_SIZE - 1);
            printf("line is %s\n", line[store.j]);
            printf("rest line is %s\n", store.rest_line);
            i = 0;
            store.j++;
            store.index_n = check_n(store.rest_line);
            printf("index n is %d\n", store.index_n);
            free(buf);
            return (1);
        }
        line[store.j] = ft_strjoin(line[store.j], buf);
        // printf("%s\n", line[store.j]);
        ft_bzero(buf, BUFFER_SIZE + 1);
        i = 0;
    }
    // store.j++;
    // store.index_n = check_n(store.rest_line);
}
