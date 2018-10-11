/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:25:05 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 13:56:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *t)
{
	size_t	tlen;

	tlen = ft_strlen(t);
	if (*s == '\0')
		return (*s == *t ? (char*)s : NULL);
	while (*s)
		if (ft_strncmp(s, t, tlen) == 0)
			return ((char*)s);
		else
			s++;
	return (NULL);
}
