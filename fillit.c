/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:16:27 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/12 21:43:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "llist.h"

static int	is_valid(t_grid *grid, t_grid *piece, int x, int y)
{
	size_t	px;
	size_t	py;

	py = 0;
	while (py < piece->size)
	{
		px = 0;
		while (px < piece->size)
		{
			if (piece->data[py][px] == '#')
			{
				if (y + py >= grid->size || x + px >= grid->size)
					return (0);
				if (grid->data[y + py][x + px] != '.')
					return (0);
			}
			px++;
		}
		py++;
	}
	return (1);
}

static int	place(t_grid *grid, t_grid *piece, int x, int y, int index)
{
	size_t	px;
	size_t	py;

	if (!is_valid(grid, piece, x, y))
		return (0);
	py = 0;
	while (py < piece->size)
	{
		px = 0;
		while (px < piece->size)
		{
			if (piece->data[py][px] == '#')
			{
				grid->data[y + py][x + px] = 'A' + index;
			}
			px++;
		}
		py++;
	}
	return (1);
}

static void	remove(t_grid *grid, t_grid *piece, int x, int y)
{
	size_t	px;
	size_t	py;

	py = 0;
	while (py < piece->size)
	{
		px = 0;
		while (px < piece->size)
		{
			if (piece->data[py][px] == '#')
			{
				grid->data[y + py][x + px] = '.';
			}
			px++;
		}
		py++;
	}
}

static int	fillit(t_grid *grid, t_llist *pieces)
{
	size_t			x;
	size_t			y;
	t_llist_node	*piece_lst;
	t_grid			*piece;
	int				i;

	i = 0;
	piece_lst = pieces->start;
	while ((piece_lst = llist_next(piece_lst, i)))
	{
		i++;
		piece = (t_grid*)piece_lst->data;
		y = 0;
		while (y < grid->size)
		{
			x = 0;
			while (x < grid->size)
			{
				if (place(grid, piece, x, y, piece_lst->index))
				{
					piece_lst->available = 0;
					if (fillit(grid, pieces))
						return (1);
					remove(grid, piece, x, y);
					piece_lst->available = 1;
				}
				x++;
			}
			y++;
		}
	}
	return (i == 0);
}

t_grid		*fill_smallest_grid(t_llist *pieces)
{
	size_t	size;
	t_grid	*grid;

	size = 3;
	while ((grid = grid_new(size++)))
	{
		if (fillit(grid, pieces))
			return (grid);
		grid_free(grid);
	}
	return (NULL);
}
