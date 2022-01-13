/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:56:54 by lmann             #+#    #+#             */
/*   Updated: 2021/10/12 18:47:42 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destc;
	const char	*srcc;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	destc = (char *)dest;
	srcc = (const char *)src;
	while (n--)
		destc[n] = srcc[n];
	return (dest);
}
