/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:18:35 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 13:48:56 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	len;

	len = (ssize_t)ft_strlen(s);
	while (len >= 0)
		if (s[len] == c)
			return ((char*)s + len);
		else
			len--;
	return (NULL);
}
