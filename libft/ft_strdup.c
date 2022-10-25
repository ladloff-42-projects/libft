/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:14:52 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/22 14:59:56 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc(ft_strlen(s1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
