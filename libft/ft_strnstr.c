/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:07:37 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/22 22:01:14 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t	needle_len;

	i = -1;
	needle_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (len > 2147483647 || len == 0)
		return (NULL);
	while (++i <= (len - needle_len))
	{
		if ((haystack[0] == needle[0]) &&
				(!memcmp(haystack, needle, needle_len)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

/*int	main(void)
{
	char *empty = (char*)"";

	printf("debug1: %s\n", ft_strnstr(empty, "Hello", -1));
	printf("debug2: %s\n", strnstr(empty, "Hello", -1));
}*/

