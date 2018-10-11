/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:51:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 22:20:19 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*node;
	t_list	*tmp;
	t_list	*cpy;
	t_list	*head;

	node = lst;
	tmp = f(lst);
	cpy = ft_lstnew(tmp->content, tmp->content_size);
	head = cpy;
	while (node->next)
	{
		tmp = f(node->next);
		cpy->next = ft_lstnew(tmp->content, tmp->content_size);
		cpy = cpy->next;
		node = node->next;
	}
	return (head);
}
