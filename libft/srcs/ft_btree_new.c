/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:31:42 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 15:24:55 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_new(void *data)
{
	t_btree *node;

	node = (t_btree*)malloc(sizeof(t_btree));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return (node);
}
