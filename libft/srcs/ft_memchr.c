/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:07:37 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 13:22:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *us;
	unsigned char uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
		if (*us == uc)
			return ((void*)us);
		else
			us++;
	return (NULL);
}
