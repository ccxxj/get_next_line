/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testleaks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:58:01 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/12 11:29:18 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
    int i;
    i = 0;
    char *line;
	char *array[] = {"normal.txt", "fewchar_perline.txt", "64bit_line.txt", "64bit_paragraph.txt", "long_line.txt", NULL};
	while (array[i])
	{
		fd = open(array[i], O_RDONLY);
		get_next_line(fd, &line);
		free(line);
		system("leaks a.out");
		i++;
	}
	return (0);
}
