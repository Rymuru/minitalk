/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/09/28 19:22:44 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois recuperer le pid et l'afficher*/
/*je dois recevoir la chaine de caractere d'un client a la fois et l'afficher*/

#include "minitalk.h"

static int	main(void)
{
	int		pid;
	char	*line;

	pid = getpid();
	ft_printf("%d\n", pid);
	line = malloc(1000 * (sizeof(char)));
	line[999] = '\0';
	signal(SIGUSR1, sig_handler(0, line));
	signal(SIGUSR2, sig_handler(1, line));
	while (1)
		pause();
	return (0);
}

/*un signal = un bit*/
/*donc il va falloir reconstituer les caracteres a l'arrivee*/

int	sig_handler(int n, char *line)
{
	int		i;
	char	c;

	i = 0;
	if (ft_strlen(line + 1) == '\0')
		line = biggerline(line);
	c = reconstruct(n);
}

static char	*biggerline(char *line)
{
	int		i;
	char	*bigline;

	i = ft_strlen(line) + 1000;
	bigline = malloc(i * sizeof(char));
	ft_strlcpy(bigline, line, i - 1000);
}

static char	reconstruct(int signo)
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
