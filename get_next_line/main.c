/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:42:29 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/01 22:19:35 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    // char buf[6];
    // fd = open(argv[1], O_RDONLY);  // to check the standard input first

    fd = open("a.txt", O_RDONLY);
    // write(1, "s", 1);
    // int i = get_next_line(fd, &line);
    // int result = read(fd, buf, 5);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    // printf("%d\n", result);
    // printf("%s\n", line);
    // printf("%d\n", fd);
    // printf("%d\n", i);
    return (0);
}
