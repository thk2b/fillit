/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:33:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 21:29:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

t_grid	*grid_new(size_t size)
{
	t_grid	*grid;
	size_t	i;

	MALLOC_CHECK(grid = (t_grid*)malloc(sizeof(t_grid)));
	i = 0;
	grid->size = size;
	grid->c = 'A';
	MALLOC_CHECK(grid->data = (char**)malloc(sizeof(char*) * size));
	while (i < size)
		MALLOC_CHECK(grid->data[i++] = (char*)ft_memalloc(sizeof(char) * size));
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
		ft_putendl(grid->data[y++]);
}
