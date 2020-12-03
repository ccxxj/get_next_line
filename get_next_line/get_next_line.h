/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:35:10 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/01 21:05:42 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

typedef struct	    s_list
{
	char	*rest_line;
	int	    index_n;
	int	    j;
}                   t_store;

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *str, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int     get_next_line(int fd, char **line);

#endif