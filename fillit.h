/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 18:17:39 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define MALLOC_CHECK(addr) if((addr) == 0) return (0)

typedef struct	s_grid
{
	size_t	size;
	char	**data;
}				t_grid;

t_grid	*grid_new(size_t size);
void	grid_free(t_grid *grid);
t_list	*read_pieces(int fd);
t_grid	*fill_smallest_grid(t_list *pieces);
void	write_grid(t_grid *grid);

#endif
