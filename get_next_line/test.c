/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xxu <xxu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:49:49 by xxu           #+#    #+#                 */
/*   Updated: 2020/11/26 20:38:23 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct	    s_list
{
	char	*rest_line;
	int	    index_n;
}                   t_store;

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

int	get_next_line(int fd, char **line)
{
    static  t_store *store;
    int n;
    int result;
    char *temp;

    temp = NULL;
    if (store->rest_line) // when the rest line exist contains \n
    {
        n = check_n(store->rest_line);
        if (n > -1) //check later, this is to cpy the before n to line, and rest to the struct rest
        {
            ft_memmove(*line, store->rest_line, 0, n);
            store->rest_line = ft_substr(store->rest_line, n, ); // figure out the lenth
            return (1);
        }
        else
            temp = store->rest_line;
        
    }
    while (1)
    {
        result = read(fd, buf, BUFFER_SIZE);
        if (result == -1)
            return (-1);
        while (result == BUFFER_SIZE && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
        if (result == 0)
        {
            *line = strjoin(temp, buf);
            return (0);
        }
        else if (i < result)
        {
            *line = strjoin(temp, ft_substr(buf, i));
            store->rest_line = ft_end(buf, i, BUFFER_SIZE - i);
        }
        ft_bzero(buf);
    }
}