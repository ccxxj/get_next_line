/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maintest.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:03:48 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/12/04 17:14:55 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	int i = 0;
	char buf[6];

	fd = open("a.txt", O_RDONLY);
	int result = read(fd, buf, 5);
	// printf("result is %d\n", result);
	// printf("buf is %s\n", buf);
	while (i < 5)
	{
		printf("buf %d is %d\n", i, (int)buf[i]);
		if (buf[i] == 10)
			printf("suc");
		if (buf[i] == 97)
			printf("fuc");
		i++;
	}
}