/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:38:45 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/28 18:09:57 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	reconstruct(char c, int char_size)
{
	c |= 1 << char_size;
	return (c);
}

int	add_len(int n, int char_size)
{
	n |= 1 << char_size;
	return (n);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
