/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:22:44 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/20 22:53:57 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	*is_find;

	p_s = (unsigned char*)s;
	is_find = NULL;
	while (s != NULL && n--)
		if ( *p_s != (unsigned char)c )
			p_s++;
	else
	{
		is_find = p_s;
		break ;
	}
	return (is_find);
}
