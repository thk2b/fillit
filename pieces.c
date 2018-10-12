/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:17:38 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/11 19:08:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "get_next_line.h"

static int	read_piece(int fd, t_list **list)
{
	size_t		i;
	size_t		len;
	char	*line;
	t_list	*item;
	t_grid	*piece;

	i = 0;
	MALLOC_CHECK(piece = grid_new(4));
	while (i < piece->size)
	{
		if (get_next_line(fd, &line) != 1)
			return (-1);
		len = ft_strlen(line);
		if (len == 0)
			return (-1);
		if (len != piece->size)
			return (-1);
		piece->data[i++] = line;
	}
	if (i != piece->size)
		return (-1);
	MALLOC_CHECK(item = ft_lstnew((void*)piece, sizeof(t_grid)));
	ft_lstadd(list, item);
	return (1);
}

t_list		*read_pieces(int fd)
{
	t_list	*head;
	int		status;
	char	*line;

	while ((status = read_piece(fd, &head)))
	{
		if (get_next_line(fd, &line) < 1)
			break;
		free(line);
	}
	if (status == -1) //TODO: free
		return (NULL);
	return (head);
}
