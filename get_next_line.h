/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:35:10 by xxu           #+#    #+#                 */
/*   Updated: 2020/12/10 21:36:29 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

typedef struct	    s_list
{
	char	*rest_line;
	char	buf[BUFFER_SIZE + 1];
	int	    index_n;
	int	    flag;
	int	    i;
	int	    result;
	int		initialization;
}                   t_store;

// char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *str, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int     get_next_line(int fd, char **line);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_strcat(char *s1, char *s2);

#endif