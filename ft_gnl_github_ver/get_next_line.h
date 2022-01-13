/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:43:43 by lmann             #+#    #+#             */
/*   Updated: 2021/12/20 10:00:43 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_free_rest(char *mem, int read_val);
char	*ft_strjoin(const char *str1, const char *str2);
int		ft_get_buffer(int fd, char *buf, int buf_size);

#endif
