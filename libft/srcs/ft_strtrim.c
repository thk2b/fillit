/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 20:51:52 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 15:14:47 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	const char	*start;
	size_t		len;
	char		*t;

	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	if (*s == '\0')
		return (ft_strdup(""));
	start = s;
	while (*s)
		s++;
	s--;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s--;
	len = s - start + 1;
	if ((t = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_strncpy(t, start, len);
	t[len] = '\0';
	return (t);
}
