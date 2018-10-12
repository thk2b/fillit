/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:33:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 23:55:37 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

t_grid	*grid_new(size_t size)
{
	t_grid	*grid;
	size_t	y;

	MALLOC_CHECK(grid = (t_grid*)malloc(sizeof(t_grid)));
	grid->size = size;
	grid->c = 'A';
	MALLOC_CHECK(grid->data = (char**)malloc(sizeof(char*) * size));
	y = 0;
	while (y < size)
	{
		MALLOC_CHECK(grid->data[y] = (char*)malloc(sizeof(char) * size));
		ft_memset(grid->data[y++], '.', size);
	}
	return (grid);
}

void	grid_free(t_grid *grid)
{
	size_t	i;

	i = 0;
	while (i < grid->size)
		free(grid->data[i++]);
	free(grid->data);
	free(grid);
}

void	write_grid(t_grid *grid)
{
	size_t	y;

	y = 0;
	while (y < grid->size)
	{
		write(1, grid->data[y++], grid->size);
		write(1, "\n", 1);
	}
}
