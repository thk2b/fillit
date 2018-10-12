/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:16:27 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 20:25:17 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "llist.h"

static int	place(t_grid *grid, t_grid *piece, int x, int y)
{
	
}

static void	remove(t_grid *grid, t_grid *piece, int x, int y)
{

}

static int	fillit(t_grid *grid, t_llist_node *piece_lst)
{
	int x;
	int y;
	t_grid	*piece;

	if (piece_lst == NULL)
		return (1);
	piece = (t_grid*)piece_lst->data;
	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			if (place(grid, piece, x, y))
			{
				if (fillit(grid, piece_lst->next))
					return (1);
				remove(grid, piece, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_grid		*fill_smallest_grid(t_llist *pieces)
{
	size_t	size;
	t_grid	*grid;

	size = 1;
	while ((grid = grid_new(size++)))
	{
		if (fillit(grid, pieces->start))
			return (grid);
		grid_free(grid);
	}
	return (NULL);
}
