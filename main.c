/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:42:29 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/03 21:20:27 by xxu           ########   odam.nl         */
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
    int result = 0;
    fd = open("fewchar_perline.txt", O_RDONLY);
    result = get_next_line(fd, &line);
    printf("%d\n", result);
    printf("%s\n", line);

    while (result > 0)
    {
        result = get_next_line(fd, &line);
        printf("%s\n", line);
    }
    // // char buf[6];
    // // fd = open(argv[1], O_RDONLY);  // to check the standard input first

    // fd = open("a.txt", O_RDONLY);
    // // write(1, "s", 1);
    // // int i = get_next_line(fd, &line);
    // // int result = read(fd, buf, 5);
    // get_next_line(fd, &line);
    // printf("first line is %s\n", line);
    // result = get_next_line(fd, &line);

    // // // printf("second line is%s\n", line[1]);
    // // printf("line is%s\n", line);
    // printf("second line is %s, with result: %d\n", line, result);
    // result = get_next_line(fd, &line);
    // // // printf("third line is%s\n", line[2]);
    // printf("third line is %s, with result: %d\n", line, result);
    // result = get_next_line(fd, &line);
    // // // printf("third line is%s\n", line[2]);
    // printf("fourth line is %s, with result: %d\n", line, result);
    // // get_next_line(fd, &line);
    // // // printf("fourth line is%s\n", line[3]);
    // // printf("fourth line is%s\n", line);
    // // // printf("%d\n", result);
    // // printf("%s\n", line);
    // // printf("%d\n", fd);
    // // printf("%d\n", i);
    return (0);
}