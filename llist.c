/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:58:39 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/13 19:31:37 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"
#include "fillit.h"

static t_llist		*llist_new_head(void)
{
	t_llist *h;

	LLIST_MALLOC_CHECK(h = (t_llist*)malloc(sizeof(t_llist)));
	h->start = NULL;
	h->last = NULL;
	h->len = 0;
	return (h);
}

static t_llist_node	*llist_new_node(void *data)
{
	t_llist_node	*n;

	LLIST_MALLOC_CHECK(n = (t_llist_node*)malloc(sizeof(t_llist_node)));
	n->data = data;
	n->next = NULL;
	n->index = -1;
	return (n);
}

void				llist_push(t_llist **head, void *data)
{
	t_llist_node	*n;

	if ((n = llist_new_node(data)) == NULL)
		return ((void)NULL);
	if (*head == NULL)
	{
		if ((*head = llist_new_head()) == NULL)
			return ((void)NULL);
		(*head)->start = n;
		n->index = 0;
	}
	else
	{
		n->index = (*head)->last->index + 1;
		(*head)->last->next = n;
	}
	(*head)->last = n;
	(*head)->len++;
}

void				llist_del(t_llist **head, t_llist_del_fn del)
{
	size_t			i;
	t_llist_node	*n;
	t_llist_node	*t;

	i = 0;
	n = (*head)->start;
	while (n)
	{
		t = n;
		n = t->next;
		del(t->data);
		free(t);
	}
	free(*head);
	*head = NULL;
}
