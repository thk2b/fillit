/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:35:18 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 14:08:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(const char *s, char c, const char *t)
{
	size_t	slen;
	size_t	len;
	char	*j;

	slen = ft_strlen(s);
	len = slen + ft_strlen(t) + 1;
	if ((j = (char*)malloc((len + 2) * sizeof(char))) == NULL)
		return (NULL);
	ft_strcpy(j, s);
	j[slen] = c;
	ft_strcpy(j + slen + 1, t);
	return (j);
}
