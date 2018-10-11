/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:29:10 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 20:02:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_find(t_btree *root, void *key, void *ctx,
	int (*cmp)(void *ctx, void*, void*))
{
	t_btree	*curr;
	int		diff;

	curr = root;
	while (curr != NULL)
		if ((diff = cmp(ctx, key, curr->data)) == 0)
			return (curr->data);
		else if (diff > 0)
			curr = curr->right;
		else
			curr = curr->left;
	return (NULL);
}
