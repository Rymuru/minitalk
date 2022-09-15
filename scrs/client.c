/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:44 by bcoenon           #+#    #+#             */
/*   Updated: 2022/09/15 17:05:36 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*je dois prendre en entree le PID du serveur et la chaine de caracteres*/
/*je dois envoyer la chaine de cracteres au serveur*/

/* 1: verification de la validite du pid*/
/* 2: verification de la validite de la chaine*/

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	if (check_pid(av[1] != 0))
		return (1);
}

/*need to check if only numbers, and min and max value*/

static long int	check_pid(char *pid)
{
	long int	n;

	n = 0;
	if (pid[0] == '/0')
		return (-1);
	while (pid[n])
	{
		if (pid[n] < '0' || pid[n] > '9')
			return (-1);
		n++;
	}
	n = ft_atoi(pid);
	if (n > 4194304 || n < 1)
		return (-1);
	return (n);
}

static void	send(char c, int pid)
{
	while (c)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSER2);
		c = c / 2;
	}
}
