/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:16:27 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 22:32:02 by tkobb            ###   ########.fr       */
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

static int	place(t_grid *grid, t_grid *piece, int x, int y)
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
				grid->data[y + py][x + px] = grid->c;
			}
			px++;
		}
		py++;
	}
	grid->c++;
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
			if (piece->data[py][px] == '*')
			{
				grid->data[y + py][x + px] = '.';
			}
			px++;
		}
		py++;
	}
	grid->c--;
}

static int	fillit(t_grid *grid, t_llist_node *piece_lst)
{
	size_t x;
	size_t y;
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
