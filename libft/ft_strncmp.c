/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:52:24 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/25 21:34:53 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (!n)
		return (0);
	while (s1[++i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
