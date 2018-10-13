/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:52:50 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/12 21:40:44 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
# define LLIST_H
# include <stdlib.h>
# define LLIST_MALLOC_CHECK(addr) if((addr) == 0) return (0)

typedef struct	s_llist_node
{
	void				*data;
	struct s_llist_node	*next;
	int					available;
	int					index;
}				t_llist_node;

typedef struct	s_llist
{
	size_t			len;
	t_llist_node	*start;
	t_llist_node	*last;
}				t_llist;

typedef void	(*t_llist_del_fn)(void*);

void			llist_push(t_llist **head, void *data);
void			llist_del(t_llist **head, t_llist_del_fn del);
t_llist_node	*llist_next(t_llist_node *start, int skip);

#endif
