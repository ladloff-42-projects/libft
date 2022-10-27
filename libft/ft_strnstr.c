/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:07:37 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 09:28:44 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = -1;
	if (!haystack || haystack == needle)
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
/*
int	main(void)
{
	char haystack[30] = "aaabcabcd";
	//char needle[10] = "aabc";

	printf("ft_strnstr: [%s]\n", ft_strnstr(haystack, "cd", 8));
	printf("strnstr: [%s]\n", strnstr(haystack, "cd", 8));
	//printf("haystack + 5: [%s]\n", haystack + 5);
}
*/
