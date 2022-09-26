/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/09/26 18:41:11 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois recuperer le pid et l'afficher*/
/*je dois recevoir la chaine de caractere d'un client a la fois et l'afficher*/

#include "minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		assembly();
}

/*un signal = un bit*/
/*donc il va falloir reconstituer les caracteres a l'arrivee*/

char	*assembly(void)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(1000 * (sizeof(char)));
	while (signal)
	{
		line[i] = reconstruct(signal);
		++i;
	}
	return (line);
}

char	reconstruct(int signo)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = c * 2;
		if (signo == SIGUSR2)
			c = c + 1;
		i++;
	}
	return (c);
}
