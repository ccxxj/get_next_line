/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:42:29 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/10 21:37:52 by xxu           ########   odam.nl         */
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
    i = 2;
    char *line;
    // char buf[6];
    int result = 0;
    // fd = open("normal.txt", O_RDONLY);
    // fd = open("fewchar_perline.txt", O_RDONLY);
    // fd = open("64bit_line.txt", O_RDONLY);
    // fd = open("64bit_paragraph.txt", O_RDONLY);
    // fd = open("long_line.txt", O_RDONLY);
    fd = open("a.txt", O_RDONLY);
    result = get_next_line(fd, &line);
    printf("%d | %d | %s\n", result, 1, line);
    // free(line);
    while (result > 0)
    {
        result = get_next_line(fd, &line);
        printf("%d | %d | %s\n", result, i, line);
        // free(line);
        // system("leaks a.out");
        i++;
    }
    result = get_next_line(fd, &line);
    printf("%d | %d | %s\n", result, i, line);
    // free(line);

    // system("leaks a.out");
    return (0);
}
