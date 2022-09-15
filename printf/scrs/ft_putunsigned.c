/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:33:17 by bcoenon           #+#    #+#             */
/*   Updated: 2021/11/24 11:53:27 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_status(unsigned int n)
{
	int	total;

	total = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		total++;
		n = n / 10;
	}
	return (total);
}

int	ft_putunsigned(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
	return (ft_status(n));
}
