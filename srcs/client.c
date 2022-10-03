/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:44 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/03 19:45:46 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*je dois prendre en entree le PID du serveur et la chaine de caracteres*/
/*je dois envoyer la chaine de cracteres au serveur*/

/* 1: verification de la validite du pid*/
/* 2: verification de la validite de la chaine*/

int	main(int ac, char **av)
{
	struct sigaction	type;
	sigset_t			sos;
	long int			pid;
	int					i;

	i = 0;
	if (ac != 3)
		return (1);
	pid = check_pid(av[1]);
	if (pid <= 0)
		return (1);
	sigemptyset(&sos);
	sigaddset(&sos, SIGUSR2);
	type.sa_flags = SA_SIGINFO;
	while (av[2][i])
	{
		send(av[2][i], pid);
		i++;
	}
}

/*need to check if only numbers, and min and max value*/

long int	check_pid(char *pid)
{
	long int	n;

	n = 0;
	if (pid[0] == '\0')
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

void	send(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c / 2;
		++i;
	}
}
