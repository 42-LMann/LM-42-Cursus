/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:56:36 by lmann             #+#    #+#             */
/*   Updated: 2021/10/29 12:11:59 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t				i;
	unsigned char		*src;

	i = 0;
	src = (unsigned char *)str;
	while (i < len)
	{
		src[i] = c;
		i++;
	}
	return (str = src);
}
