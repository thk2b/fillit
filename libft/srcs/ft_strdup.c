/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:20:41 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/11 19:49:44 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*t;
	char	*u;

	len = ft_strlen(s) + 1;
	if ((t = (char*)malloc(len * sizeof(char))) == NULL)
		return (NULL);
	u = t;
	while (*s)
		*t++ = *s++;
	*t = '\0';
	return (u);
}
