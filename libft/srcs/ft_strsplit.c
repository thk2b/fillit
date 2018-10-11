/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 21:00:30 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 21:49:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*alloc_str(const char *start, const char *end)
{
	char	*s;
	size_t	len;

	len = (end - start);
	if ((s = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(s, start, len);
	s[len] = '\0';
	return (s);
}

static char		**alloc_splits(const char *s, char c)
{
	size_t	count;

	count = 1;
	if (*s == c)
		s++;
	while (*s)
		if (*s++ == c && *s && *s != c)
			count++;
	return ((char**)malloc(count * sizeof(char**)));
}

char			**ft_strsplit(const char *s, char c)
{
	const char	*t;
	char		**strv;
	size_t		i;

	t = s;
	i = 0;
	if ((strv = alloc_splits(s, c)) == NULL)
		return (NULL);
	while (s && *s)
	{
		if ((t = ft_strchr(s, (int)c)) == NULL)
			strv[i++] = alloc_str(s, s + ft_strlen(s));
		else
		{
			if (t != s)
				strv[i++] = alloc_str(s, t);
			while (*t && *t == c)
				t++;
		}
		s = t;
	}
	strv[i] = NULL;
	return (strv);
}
