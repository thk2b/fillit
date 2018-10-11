/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:58:18 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 18:02:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_add(t_btree **root,
	void *data, void *ctx, int (*cmp)(void *ctx, void*, void*))
{
	t_btree	**curr;

	if (*root == NULL)
		return ((void)(*root = ft_btree_new(data)));
	curr = root;
	while (*curr != NULL)
		if (cmp(ctx, data, (*curr)->data) > 0)
			curr = &(*curr)->right;
		else
			curr = &(*curr)->left;
	*curr = ft_btree_new(data);
}
