/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:26:49 by bcoenon           #+#    #+#             */
/*   Updated: 2021/11/24 14:48:32 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_addr(uint64_t nb)
{
	char	*stock;

	stock = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(stock[nb]);
	else
	{
		ft_print_addr(nb / 16);
		ft_print_addr(nb % 16);
	}
}

static int	nb_carac(uint64_t n)
{
	uint64_t	total;

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

int	ft_adress(void *addr)
{
	uint64_t	nb;

	if (addr == NULL)
		return (ft_putstr(OSNUL));
	nb = (uint64_t)addr;
	ft_putchar('0');
	ft_putchar('x');
	ft_print_addr(nb);
	return (nb_carac(nb) + 2);
}
