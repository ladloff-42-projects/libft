/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:26:41 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/26 15:07:07 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_check_in_set(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_pos;
	size_t	end_pos;
	size_t	total_len;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start_pos = -1;
	end_pos = ft_strlen(s1);
	while (s1[++start_pos] && ft_check_in_set(s1[start_pos], set))
		;
	while (start_pos < --end_pos && ft_check_in_set(s1[end_pos], set))
		;
	total_len = (end_pos - start_pos + 1);
	trimmed_str = malloc(total_len * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	memmove(trimmed_str, s1 + start_pos, total_len);
	trimmed_str[total_len] = '\0';
	return (trimmed_str);
}
/*
int	main(void)
{
	printf("ft_strtrim: [%s]\n", ft_strtrim("   xxxtripouille", " x"));
	return (0);
}
*/
