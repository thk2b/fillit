/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:25:05 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 14:22:47 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *t, size_t len)
{
	size_t	tlen;

	if (*s == '\0')
		return (*t == '\0' ? (char*)s : (NULL));
	tlen = ft_strlen(t);
	if (tlen == len)
		return (ft_strncmp(s, t, len) == 0 ? (char*)s : NULL);
	if (tlen > len)
		return (NULL);
	while (*s && len && (tlen - 1 - len--) > 0)
		if (ft_strncmp(s, t, tlen) == 0)
			return ((char*)s);
		else
			s++;
	return (NULL);
}
