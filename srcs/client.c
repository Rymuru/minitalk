/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:44 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/16 04:10:30 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*je dois prendre en entree le PID du serveur et la chaine de caracteres*/
/*je dois envoyer la chaine de cracteres au serveur*/

/* 1: verification de la validite du pid*/
/* 2: verification de la validite de la chaine*/

int	main(int ac, char **av)
{
	long int			pid;
	int					i;

	i = 0;
	if (ac != 3)
	{
		write(2, "usage: ./client <pid> <string to send>\n", 39);
		return (1);
	}
	pid = check_pid(av[1]);
	if (pid <= 0)
	{
		write(2, "usage: ./client <pid> <string to send>\n", 39);
		return (1);
	}
	send_len(ft_strlen(av[2]), pid);
	while (av[2][i])
	{
		send(av[2][i], pid);
		i++;
	}
	send('\0', pid);
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

/*cette fonction separe les char en signaux et les envois*/

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
		usleep(TIME);
	}
}

/*cette fonction envoie la longueur de la chaine au serveur*/

void	send_len(int len, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len % 2 == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len / 2;
		++i;
		usleep(TIME);
	}
}
