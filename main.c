/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:02:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 16:16:06 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	usage()
{
	return (1);
}

int	main(int ac, char **av)
{
	t_list *pieces;
	t_grid *grid;
	int fd;

	if (ac != 2)
		return (usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (write(2, "fillit: no such file\n", 22) >= -1);
	MALLOC_CHECK(pieces = read_pieces(fd));
	MALLOC_CHECK(grid = fill_smallest_grid(pieces));
	write_grid(grid);
	close(fd);
	//free
	return (0);
}
