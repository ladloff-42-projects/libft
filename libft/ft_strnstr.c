/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:07:37 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 22:11:41 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = -1;
	if (!needle[0])
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && ++i < len)
	{
		if (!(i + ft_strlen(needle) > len))
			if (haystack[0] == needle[0]
				&& !ft_strncmp(haystack, needle, ft_strlen(needle)))
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
