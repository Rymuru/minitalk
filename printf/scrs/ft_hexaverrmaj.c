/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaverrmaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:32:51 by bcoenon           #+#    #+#             */
/*   Updated: 2021/11/24 12:03:35 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_statushexaverrmaj(unsigned int n)
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

int	ft_hexaverrmaj(unsigned int n)
{
	char	*stock;

	stock = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(stock[n]);
	else
	{
		ft_hexaverrmaj(n / 16);
		ft_hexaverrmaj(n % 16);
	}
	return (ft_statushexaverrmaj(n));
}
