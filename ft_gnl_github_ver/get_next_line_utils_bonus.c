/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:21 by lmann             #+#    #+#             */
/*   Updated: 2021/12/16 17:33:01 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	ft_free_rest(char *mem, int read_val)
{
	if (read_val == 0 && mem)
		free(mem);
}

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

int	get_buffer(int fd, char *buf, int buf_size)
{
	int		read_val;
	int		i;

	i = 1;
	read_val = read(fd, buf, 1);
	if (read_val < 1)
	{
		buf = NULL;
		return (0);
	}
	while (buf[i - 1] != '\n' && read_val > 0 && i < buf_size)
	{
		read_val = read(fd, buf + i, 1);
		if (read_val > 0)
			i++;
	}
	buf[i] = '\0';
	if (buf[i - 1] == '\n' && i == buf_size)
		i++;
	return (i);
}
