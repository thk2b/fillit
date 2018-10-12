/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardize_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:56:39 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 23:58:00 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	get_vertical_offset(t_grid *grid)
{
	size_t	y;

	y = 0;
	while (y < grid->size
		&& ft_strchr(grid->data[y], '#') == NULL)
		y++;
	return (y);
}

static size_t	get_horizontal_offset(t_grid *grid)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < grid->size)
	{
		y = 0;
		while (y < grid->size)
		{
			if (grid->data[y][x] == '#')
				return (x);
			y++;
		}
		x++;
	}
	return (x);
}

static void		swap_vertical(t_grid *grid)
{
	char	*tmp;
	size_t	y;

	y = 0;
	while (y < grid->size - 1)
	{
		tmp = grid->data[y];
		grid->data[y] = grid->data[1 + y];
		grid->data[1 + y] = tmp;
		y++;
	}
}

static void		swap_horizontal(t_grid *grid)
{
	char	tmp;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size - 1)
		{
			tmp = grid->data[y][x];
			grid->data[y][x] = grid->data[y][1 + x];
			grid->data[y][1 + x] = tmp;
			x++;
		}
		y++;
	}
}

int				standardize_piece(t_grid *piece)
{
	size_t	vertical_offset;
	size_t	horizontal_offset;

	vertical_offset = get_vertical_offset(piece);
	horizontal_offset = get_horizontal_offset(piece);
	while (vertical_offset && vertical_offset--)
		swap_vertical(piece);
	while (horizontal_offset && horizontal_offset--)
		swap_horizontal(piece);
	return (1);
}
