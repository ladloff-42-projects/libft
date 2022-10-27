/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:55:49 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/27 13:43:40 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst = lst;
	ft_lstclear(&new_lst, del);
	return (new_lst);
}
