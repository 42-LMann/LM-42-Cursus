/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:07:17 by lmann             #+#    #+#             */
/*   Updated: 2021/11/12 14:51:31 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set++ == (char)c)
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	int		start;
	int		end;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set) == 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set) == 0)
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1 + start, end - start + 1);
	return (dest);
}
