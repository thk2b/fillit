/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:06:39 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 22:18:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lp, void (*del)(void*, size_t))
{
	t_list	*node;
	t_list	*next;

	node = *lp;
	while (node)
	{
		next = node->next;
		del(node->content, node->content_size);
		free(node);
		node = next;
	}
	*lp = NULL;
}
