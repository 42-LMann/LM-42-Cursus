/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:43:04 by lmann             #+#    #+#             */
/*   Updated: 2021/12/08 11:49:54 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Return Value; read line: correct behaviour
 				 NULL: nothing else to read or an error occurred//

External functions; read, malloc, free 

Write a function which returns a line read from the file decriptor */

char	*get_next_line(int fd)
{
	int			ret;
	static char	*line;
	char		*buf;
	char		*temp;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	ret = get_buffer(fd, line, BUFFER_SIZE);
	ft_free_rest(line, ret);
	if (ret == 0)
		return (NULL);
	while (ret == BUFFER_SIZE)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ret = get_buffer(fd, buf, BUFFER_SIZE);
		ft_free_rest(buf, ret);
		if (ret == 0)
			break ;
		temp = line;
		line = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
	}
	return (line);
}
