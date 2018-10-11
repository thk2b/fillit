/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:29:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 19:02:48 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse(t_btree *node, void *ctx,
	void (*del)(void*, void*))
{
	if (node == NULL)
		return ;
	recurse(node->left, ctx, del);
	recurse(node->right, ctx, del);
	del(ctx, node->data);
	free(node);
}

void		ft_btree_del(t_btree **root, void *ctx,
	void (*del)(void*, void*))
{
	if (root == NULL)
		return ;
	recurse(*root, ctx, del);
	*root = NULL;
}
