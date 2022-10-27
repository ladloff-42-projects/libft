/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:32:40 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 21:17:22 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	size_t	i;

	i = - 1;
	while (str[++i] == 32 || (str[i] >= 9 && str[i] <= 13))
		;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	return (sign * res);
}
