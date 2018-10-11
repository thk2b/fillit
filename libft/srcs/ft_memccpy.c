/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:13:36 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 16:42:55 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	uc;
	size_t			i;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	uc = (unsigned char)c;
	while (i < len)
	{
		d[i] = s[i];
		if (s[i] == uc)
			return ((d + i + 1));
		i++;
	}
	return (NULL);
}
