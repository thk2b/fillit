/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:12:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/20 17:37:21 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	char	*t;

	len1 = ft_strlen(s1);
	t = (char*)malloc((len1 + ft_strlen(s2) + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	ft_strcpy(t, s1);
	ft_strcpy(t + len1, s2);
	return (t);
}
