/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:21:17 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 17:17:21 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	total_len;

	if (!dst && dstsize == 0)
		return (0);
	i = -1;
	dst_len = ft_strlen(dst);
	total_len = ft_strlen(src) + dst_len;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (src[++i] && dst_len + i < dstsize - 1)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (total_len);
}
