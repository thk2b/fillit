/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:58:45 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 13:23:24 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char *s;
	const unsigned char *t;

	s = (const unsigned char*)s1;
	t = (const unsigned char*)s2;
	while (len--)
	{
		if (*s != *t)
			return ((int)(*s - *t));
		s++;
		t++;
	}
	return (0);
}
