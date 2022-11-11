/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:46:01 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/10 15:46:01 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_separator(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static size_t	ft_count_strings(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && ft_check_separator(*s, c))
			s++;
		if (*s)
			i++;
		while (*s && !ft_check_separator(*s, c))
			s++;
	}
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	size_t	i;
	size_t	len_word;
	char	*word;

	len_word = -1;
	while (s[++len_word] && !ft_check_separator(s[len_word], c))
		;
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len_word)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **str)
{
	while (*str)
		free(*str++);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s && ft_check_separator(*s, c))
			s++;
		if (*s)
		{
			str[i] = ft_word(s, c);
			if (!str[i++])
				return (ft_free(str));
		}
		while (*s && !ft_check_separator(*s, c))
			s++;
	}
	str[i] = NULL;
	return (str);
}
