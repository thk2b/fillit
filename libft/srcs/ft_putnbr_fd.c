/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:25:42 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/01 19:40:58 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long	un;
	unsigned long	next_pow;
	unsigned long	pow;

	if (n < 0)
	{
		un = (unsigned long)(-1 * (long)n);
		ft_putchar_fd('-', fd);
	}
	else
		un = (unsigned long)n;
	pow = 1;
	while ((next_pow = 10 * pow) <= un && next_pow)
		pow = next_pow;
	while (pow)
	{
		ft_putchar_fd((un / pow % 10) + '0', fd);
		pow /= 10;
	}
}
