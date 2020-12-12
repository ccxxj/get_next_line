/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:18:42 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/11 16:28:03 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_bzero(void *str, size_t n)
	{
		int i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
		n--;
	}
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return(0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

