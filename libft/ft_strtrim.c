/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:26:41 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 20:23:29 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(const char *set, char c)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	size_t	total_len;
	char	*str_trim;

	if (!s1 || !set)
		return (NULL);
	start = -1;
	while (s1[++start] && ft_is_in_set(set, s1[start]))
		;
	end = ft_strlen(s1);
	while (start < --end && ft_is_in_set(set, s1[end]))
		;
	str_trim = malloc((end - start + 2) * sizeof(char));
	if (!str_trim)
		return (NULL);
	total_len = (end - start + 1);
	memmove(str_trim, s1 + start, total_len);
	str_trim[total_len] = '\0';
	return (str_trim);
}
