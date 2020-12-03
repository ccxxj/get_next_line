/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:33:05 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/03 21:35:23 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static  t_store store;
static	int store_initialized = 0;

int check_n(char *str)//return the index position of n, if no \n return -1
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

int check_rest_line(char **line, char *str, int n) //if no \n return 0, otherwise split and return 1
{
    int len;

    if (str)
    {        
        if (n > -1)
        {
            line[0] = ft_strjoin(line[0], ft_substr(str, 0, n));
            len = ft_strlen(str);
            store.rest_line = ft_substr(str, n + 1, len - n);
            store.index_n = check_n(store.rest_line);
            return (1);
        }
        else
            line[0] = ft_strjoin(line[0], ft_strdup(str));
    }
    return (0);
}


int	get_next_line(int fd, char **line)
{
    int i;
    int n;
    int result;
    char *buf;

    if (fd == -1 || line == NULL || BUFFER_SIZE <= 0)
        return (-1);
	if (!store_initialized)
	{
		store.rest_line = NULL;
		store.index_n = 0;
		store.flag = 0;
		store_initialized = 1;
	}
    line[0] = "\0";
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (-1);
    ft_bzero(buf, BUFFER_SIZE + 1);
    i = check_rest_line(line, store.rest_line, store.index_n);
    if (store.flag == 1 && i == 1 && store.index_n == -1)//try to figure out why i===1 work
        return (0);
    if (i == 1)
        return (1);
    while (1)
    {
        result = read(fd, buf, BUFFER_SIZE);
        if (result == -1)
            return (-1);
        n = check_n(buf);
        if (result < BUFFER_SIZE)
        {
            store.rest_line = buf;
            i = check_rest_line(line, store.rest_line, n);
            store.flag = 1;
            if (i == 0)
            {
                free(buf);
                return(0);
            }
            free(buf);
            return (1);
        }
        if (n == -1)
        {
            line[0] = ft_strjoin(line[0], buf);
            ft_bzero(buf, BUFFER_SIZE + 1);
        }
        if (n > -1)
        {
            line[0] = ft_strjoin(line[0], ft_substr(buf, 0, n));
            store.rest_line = ft_substr(buf, n + 1, BUFFER_SIZE - 1);
            store.index_n = check_n(store.rest_line);
            i = 0;
            free(buf);
            return (1);
        }
    }   
}