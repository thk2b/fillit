/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_preorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:45:27 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 20:03:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_preorder(t_btree *root, void *ctx,
	void (*f)(void *ctx, void*))
{
	if (root == NULL)
		return ;
	f(ctx, root->data);
	ft_btree_preorder(root->left, ctx, f);
	ft_btree_preorder(root->right, ctx, f);
}
