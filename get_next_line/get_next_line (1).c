/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:14:09 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/25 08:24:58 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		s_list
{
	char	*buf;
	char	*last_line; //replace the newline to last_line, this is to record the last read line
}

char *new_line(char *buf, int i)
{
	char	*temp;
	char	*newline;

	temp = (char *)malloc((i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[i] = '\0';
	ft_strlcpy(temp, buf, i - 1);
	ft_strjoin(*newline, temp);
	free(temp);//question: can I also just not malloc temp
	return (newline);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf; // to remove once the static buf established
	int			result;
	int			i;

	i = 0;
	while (1)
	{
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
			return (-1);
		while (result == BUFFER_SIZE && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
		i = ft_strlen(buf); //when result != buffer_size
		*line = new_line(buf, i);
		if (!*line) //if allocation of temp memory is not sucessful
			return (-1);
		if (result == 0)
			return (0);
		if (i < result)
		{
			ft_offset(buf, i);
			return (1);
		}
		ft_bzero(buf); // make everything \0
	}
}