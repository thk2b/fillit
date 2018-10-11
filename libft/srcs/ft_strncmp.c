/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:10:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 14:21:08 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s, const char *t, size_t len)
{
	if (len == 0)
		return (0);
	while (--len && *s == *t && *s)
	{
		s++;
		t++;
	}
	return ((unsigned char)*s - (unsigned char)*t);
}
