/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maintest.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:03:48 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/12/10 20:03:15 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	// int i = 0;
	// char buf[6];
	// char buf1[6];
	// char buf2[6];
	// char buf3[6];
	// char buf4[6];

	// fd = open("a.txt", O_RDONLY);
	// int result = read(fd, buf, 1);
	// printf("buf is %s\n", buf);
	// printf("result is %d\n", result);
	// result = read(fd, buf1, 1);
	// printf("buf is %s\n", buf1);
	// printf("result is %d\n", result);
	// result = read(fd, buf2, 1);
	// printf("buf is %s\n", buf2);
	// printf("result is %d\n", result);
	// result = read(fd, buf3, 1);
	// printf("buf is %d\n", (int)buf3[0]);
	// printf("result is %d\n", result);
	// result = read(fd, buf4, 1);
	// printf("result is %d\n", result);



	char buf[6] = "bbbbb";	
	fd = open("a.txt", O_RDONLY);
	int result = read(fd, buf, 8);
	printf("buf is %s\n", buf);
	printf("result is %d\n", result);


	// printf("buf is %s\n", buf);
	// while (i < 5)
	// {
	// 	printf("buf %d is %d\n", i, (int)buf[i]);
	// 	if (buf[i] == 10)
	// 		printf("suc");
	// 	if (buf[i] == 97)
	// 		printf("fuc");
	// 	i++;
	// }
}

// int main()
// {
// 	char *str = "\0";
// 	if(!str)
// 		printf("NULL");
// 	else
// 		printf("notNULL");
// 	return (0);
// }