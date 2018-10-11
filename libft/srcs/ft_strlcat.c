/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:35:36 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 13:36:28 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dstl;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstl = ft_strlen(dst);
	if (dstl > dstsize)
		return (dstsize + ft_strlen(src));
	d = dst + dstl;
	s = src;
	while (*s && dstl < dstsize - 1)
	{
		dstl++;
		*d++ = *s++;
	}
	*d = '\0';
	return (dstl + ft_strlen(s));
}
