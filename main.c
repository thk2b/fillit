/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:02:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 19:07:33 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	usage(void)
{
	write(1, "usage: fillit file\n", 19);
	return (0);
}

int error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	t_list *pieces;
	// t_grid *grid;
	int fd;

	if (ac != 2)
		return (usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (error());
	if((pieces = read_pieces(fd)) == NULL)
		return (error());
	// MALLOC_CHECK(grid = fill_smallest_grid(pieces));
	// write_grid(grid);
	// close(fd);
	//free
	return (0);
}
