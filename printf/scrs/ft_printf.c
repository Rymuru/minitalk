/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:25:40 by bcoenon           #+#    #+#             */
/*   Updated: 2021/11/24 16:30:52 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sort(char flag, va_list arg)
{
	int	status;

	status = 0;
	if (flag == '%')
		status = ft_putchar('%');
	else if (flag == 'c')
		status = ft_putchar((char)va_arg(arg, int));
	else if (flag == 's')
		status = ft_putstr(va_arg(arg, char *));
	else if (flag == 'p')
		status = ft_adress(va_arg(arg, void *));
	else if (flag == 'd' || flag == 'i')
		status = ft_putnbr(va_arg(arg, int));
	else if (flag == 'u')
		status = ft_putunsigned(va_arg(arg, unsigned int));
	else if (flag == 'x')
		status = ft_hexa(va_arg(arg, unsigned int));
	else if (flag == 'X')
		status = ft_hexaverrmaj(va_arg(arg, unsigned int));
	return (status);
}

int	ft_printf(const char *type, ...)
{
	int		i;
	int		status;
	va_list	arg;

	if (type == NULL)
		return (-1);
	va_start(arg, type);
	i = 0;
	status = 0;
	while (type[i])
	{
		if (type[i] == '%')
		{
			status += ft_sort(type[i + 1], arg);
			i++;
		}
		else
		{
			write(1, &type[i], 1);
			status++;
		}
		i++;
	}
	va_end(arg);
	return (status);
}
