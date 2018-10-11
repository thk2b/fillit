/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 23:34:17 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 14:36:13 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *s;
	char *d;

	s = (char*)malloc(size * sizeof(char));
	if (s == NULL)
		return (NULL);
	d = s;
	while (size--)
		*s++ = 0;
	return ((void*)(d));
}
