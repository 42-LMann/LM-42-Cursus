/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:21 by lmann             #+#    #+#             */
/*   Updated: 2022/01/01 17:24:11 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* measures length of string */

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

/* Protection;
 * frees the allocation of buf if read_val is 0 
 * 		(defined by nothing was read). 
 * or frees the allocation of memory in terms of fd_line
 * 		if nothing was read.*/

void	ft_free_rest(char *mem, int read_val)
{
	if (read_val == 0 && mem)
		free(mem);
}

/* Return value for ft_strjoin;
 * correct behaviour; returns rest of buffer attached to fd_line
 * 0; incorrect memory allocation
 * NULL; either str1(fd_line) or str2(buf) are NULL */

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t		i;
	size_t		gnl_len1;
	size_t		gnl_len2;
	char		*append;

	if (!str1 || !str2)
		return (NULL);
	gnl_len1 = ft_strlen(str1);
	gnl_len2 = ft_strlen(str2);
	append = (char *)malloc(sizeof(char) * (gnl_len1 + gnl_len2 + 1));
	if (!append)
		return (0);
	i = 0;
	while (i < gnl_len1)
	{
		append[i] = str1[i];
		i++;
	}
	while (i < gnl_len1 + gnl_len2)
	{	
		append[i] = str2[i - gnl_len1];
		i++;
	}
	append[i] = '\0';
	return (append);
}

/* return Values for Get_buffer;
 * correct behaviour; number of bytes 
 * 		read (length of string or up to buffer size)
 * 0; nothing else to be read */

int	ft_get_buffer(int fd, char *buf, int buf_size)
{
	int		read_val;
	int		t_read_val;

	t_read_val = 1;
	read_val = read(fd, buf, 1);
	if (read_val < 1)
	{
		buf = NULL;
		return (0);
	}
	while (buf[t_read_val - 1] != '\n' && read_val > 0 && t_read_val < buf_size)
	{
		read_val = read(fd, buf + t_read_val, 1);
		if (read_val > 0)
			t_read_val++;
	}
	buf[t_read_val] = '\0';
	if (buf[t_read_val - 1] == '\n' && t_read_val == buf_size)
		t_read_val++;
	return (t_read_val);
}
