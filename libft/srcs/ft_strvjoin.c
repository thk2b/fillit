/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:03:14 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 14:08:08 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strvjoin(const char **sv, const char *sep)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	len = 0;
	while (sv[i])
		len += ft_strlen(sv[i++]);
	if (i == 0)
		return (ft_strdup(""));
	if (i == 1)
		return (ft_strdup(*sv));
	len += ft_strlen(sep) * (i - 1);
	i = 0;
	if ((s = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (sv[i])
	{
		ft_strcat(s, sv[i]);
		if (sv[++i])
			ft_strcat(s, sep);
	}
	s[len] = '\0';
	return (s);
}
