/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:21:04 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 13:39:47 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_nb_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_int_to_char(char *str, long nb, size_t i)
{
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	nb;
	char	*str;

	nb = n;
	i = ft_nb_len(n);
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_int_to_char(str, nb, i);
	return (str);
}
