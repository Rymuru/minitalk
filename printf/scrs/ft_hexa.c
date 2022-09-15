/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:48:47 by bcoenon           #+#    #+#             */
/*   Updated: 2021/11/24 10:35:26 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_statushexa(unsigned int n)
{
	int	total;

	total = 0;
	if (n == 0)
		total = 1;
	while (n > 0)
	{
		total++;
		n = n / 16;
	}
	return (total);
}

int	ft_hexa(unsigned int n)
{
	char	*stock;

	stock = "0123456789abcdef";
	if (n < 16)
		ft_putchar(stock[n]);
	else
	{
		ft_hexa(n / 16);
		ft_hexa(n % 16);
	}
	return (ft_statushexa(n));
}
