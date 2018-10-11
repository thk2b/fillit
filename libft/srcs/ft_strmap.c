/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:20:35 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/13 21:39:59 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*t;

	len = ft_strlen(s);
	i = 0;
	t = (char*)malloc((len + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	while (s[i])
	{
		t[i] = f(s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
