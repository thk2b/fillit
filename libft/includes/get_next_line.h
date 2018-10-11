/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:05:23 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/29 21:56:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 255
# define ALLOC_CHECK(p) if ((p) == NULL) return (-1)

typedef struct	s_buff
{
	char	*start;
	char	*cur;
}				t_buff;

int				get_next_line(int fd, char **line);

#endif
