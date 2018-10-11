/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 22:41:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/01 10:39:28 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	next_line(int fd, char **line, char **nl, char **tmp)
{
	char		*tmp1;
	ssize_t		nread;
	char		buf[BUFF_SIZE + 1];

	while ((*nl = ft_strchr(*tmp, '\n')) == NULL)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((nread = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (nread == 0)
		{
			if (**tmp == '\0')
				return (0);
			*line = ft_strdup((*tmp));
			**tmp = '\0';
			return (1);
		}
		tmp1 = *tmp;
		*tmp = ft_strjoin(*tmp, buf);
		free(tmp1);
	}
	return (2);
}

int			get_next_line(int fd, char **line)
{
	static char	*data[MAX_FD] = {0};
	char		*nl;
	char		*tmp;
	int			ret;

	if (line == NULL || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (data[fd] && (nl = ft_strchr(data[fd], '\n')))
	{
		*nl = '\0';
		*line = data[fd];
		data[fd] = ft_strdup(nl + 1);
		return (1);
	}
	tmp = data[fd];
	if (tmp == NULL)
		ALLOC_CHECK(tmp = ft_strdup(""));
	if ((ret = next_line(fd, line, &nl, &tmp)) != 2)
		return (ret);
	*nl = '\0';
	*line = ft_strdup(tmp);
	data[fd] = ft_strdup(nl + 1);
	free(tmp);
	return (1);
}
