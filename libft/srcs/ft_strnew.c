/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:44:54 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/24 09:05:08 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *s;

	s = (char*)malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_bzero((void*)s, len + 1);
	return (s);
}
