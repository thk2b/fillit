/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:58:23 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/12 22:33:24 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_neighbors(t_grid *grid, int x, int y)
{
	int	count;

	count = 0;
	if (y - 1 >= 0 && grid->data[y - 1][x] == '#')
		count++;
	if (y + 1 < (int)grid->size && grid->data[y + 1][x] == '#')
		count++;
	if (x - 1 >= 0 && grid->data[y][x - 1] == '#')
		count++;
	if (x + 1 < (int)grid->size && grid->data[y][x + 1] == '#')
		count++;
	return (count);
}

int			validate_piece(t_grid *piece)
{
	size_t	x;
	size_t	y;
	size_t	count;
	int		cur_contacts;
	int		contacts;

	y = 0;
	count = 0;
	contacts = 0;
	while (y < piece->size)
	{
		x = 0;
		while (x < piece->size)
		{
			if (piece->data[y][x] == '#')
			{
				count++;
				if((cur_contacts = check_neighbors(piece, (int)x, (int)y)) < 1)
					return (0);
				contacts += cur_contacts;
			}
			x++;
		}
		y++;
	}
	return (count == 4 && contacts >= 6);
}
