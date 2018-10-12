/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:33:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 20:40:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_grid	*grid_new(size_t size)
{
	t_grid	*grid;
	size_t	i;

	MALLOC_CHECK(grid = (t_grid*)malloc(sizeof(t_grid)));
	i = 0;
	grid->size = size;
	MALLOC_CHECK(grid->data = (char**)malloc(sizeof(char*) * size));
	while (i < size)
		MALLOC_CHECK(grid->data[i++] = (char*)malloc(sizeof(char)));
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
