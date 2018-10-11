/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:14:04 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 20:35:33 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*node;

	if ((node = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content_size = 0;
		node->content = NULL;
	}
	else
	{
		node->content_size = size;
		if (((node->content) = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(node->content, (void*)content, size);
	}
	node->next = NULL;
	return (node);
}
