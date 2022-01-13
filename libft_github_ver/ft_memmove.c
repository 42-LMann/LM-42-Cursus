/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:57:56 by lmann             #+#    #+#             */
/*   Updated: 2021/11/08 18:33:07 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;

	index = 0;
	if
		(src == dest)
	return (dest);
	if (src < dest)
	{
		index = n;
		while (index > 0)
		{
			index--;
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		}
	}
	else
	{
		index = 0;
		while (index < n)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	return (dest);
}
