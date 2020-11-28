/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:49:49 by xxu           #+#    #+#                 */
/*   Updated: 2020/11/28 14:10:59 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct	    s_list
{
	char	*rest_line;
	int	    index_n;
}                   t_store;
static  t_store *store;

int check_n(char *str)
{
    int i;

    while (str[i])
    {
        if (str[i] != '\n')
            i++;
        return (i);
    }
    return (-1);
}

int check_rest_line(char *temp, char *str)
{
    int n;
    int len;

    if (store->rest_line) // when the rest line exist contains \n
    {        
        n = check_n(store->rest_line);
        if (n > -1) //check later, this is to cpy the before n to line, and rest to the struct rest
        {
            ft_strlcpy(temp, store->rest_line, n + 1); // +1 is for null terminater
            len = ft_strlen(store->rest_line);
            store->rest_line = ft_substr(store->rest_line, n + 1, len - n); // figure out the lenth???? + - 1
            return (1);
        }
        else
            temp = ft_strdup(store->rest_line);
    }
    return (0);
}


int	get_next_line(int fd, char **line)
{
    int i;
    int result;
    char *temp;
    char *buf;

    temp = 0;
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (0);
    i = check_rest_line(temp, store->rest_line);
    if (i == 1)
        return (1);
    while (1)
    {
        result = read(fd, buf, BUFFER_SIZE);
        if (result == -1)
            return (-1);
        while (result == BUFFER_SIZE && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
        if (result == 0)
        {
            *line = ft_strjoin(temp, buf);
            return (0);
        }
        else if (i < result)
        {
            *line = strjoin(temp, ft_substr(buf, 0, i));
            store->rest_line = ft_substr(buf, i, BUFFER_SIZE - i);
            return (1);
        }
        ft_bzero(buf);
    }
}