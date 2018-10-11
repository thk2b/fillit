/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:13:24 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 11:35:11 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	get_pow(unsigned long n, size_t *len)
{
	unsigned long	next_pow;
	unsigned long	pow;

	pow = 1;
	while ((next_pow = 10 * pow) < n && next_pow)
	{
		(*len)++;
		pow = next_pow;
	}
	return (pow);
}

static void				compute(char *s, unsigned long n, unsigned long pow)
{
	while (pow)
	{
		*s++ = (n / pow % 10) + '0';
		pow /= 10;
	}
	*s = '\0';
}

char					*ft_itoa(int n)
{
	unsigned long	pow;
	unsigned long	un;
	int				is_neg;
	size_t			len;
	char			*s;

	len = 2;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		len++;
		un = (unsigned long)(-1 * (long)n);
	}
	else
		un = (unsigned long)n;
	pow = get_pow(un, &len);
	if ((s = (char*)malloc((len) * sizeof(char))) == NULL)
		return (NULL);
	if (is_neg)
		*s++ = '-';
	compute(s, un, pow);
	return (s - is_neg);
}
