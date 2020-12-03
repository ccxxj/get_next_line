/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 20:29:23 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/12/01 22:11:15 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char *buf;
	// line[0] = 0;
	*line = "\0";
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	int result = read(fd, buf, BUFFER_SIZE);
	*line = ft_strjoin(*line, buf);
	// line[0] = 0;
	printf("%s\n", *line);
	printf("%d\n", result);
	free(buf);
	return (result);
}