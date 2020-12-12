/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 12:31:15 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/12 13:43:20 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main ()
{
	int fd;
    int i;
    i = 2;
    char *line;
	int result = 0;
	fd = open("64bit_line.txt", O_RDONLY);
	result = get_next_line(fd, &line);
    printf("%d | %d | %s\n", result, 1, line);
	free(line);
	while (result > 0)
    {
        result = get_next_line(fd, &line);
        printf("%d | %d | %s\n", result, i, line);
        free(line);
        i++;
    }
    fd = open("64bit_paragraph.txt", O_RDONLY);
	i = 2;
	result = get_next_line(fd, &line);
    printf("%d | %d | %s\n", result, 1, line);
	free(line);
	while (result > 0)
    {
        result = get_next_line(fd, &line);
        printf("%d | %d | %s\n", result, i, line);
        free(line);
        i++;
    }
	return (0);
}
