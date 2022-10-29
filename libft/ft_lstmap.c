/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:55:49 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/28 15:16:49 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	first_new_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		new_lst = new_lst->next;
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (first_new_lst);
}
