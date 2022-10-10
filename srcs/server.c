/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/10 19:24:42 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois recuperer le pid et l'afficher*/
/*je dois recevoir la chaine de caractere d'un client a la fois et l'afficher*/

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;
	int					pid;
	sigset_t			blocked;

	sigemptyset(&blocked);
	sigaddset(&blocked, SIGUSR2);
	sigaddset(&blocked, SIGUSR1);
	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	sa.sa_mask = blocked;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

/*un signal = un bit*/
/*donc il va falloir reconstituer les caracteres a l'arrivee*/

void	ft_handler(int signo)
{
	static int		char_size = 0;
	static int		i = 0;
	static int		n = 0;
	static char		c = 0;
	static char		*line;

	if (i == 0)
	{
		if (signo == SIGUSR2)
			n = find_len(n, char_size);
		char_size++;
		if (char_size == 32)
		{
			line = malloc(n * sizeof(char));
			i++;
			char_size = 0;
		}
	}
	else
	{
		if (signo == SIGUSR2)
			c = reconstruct(c, char_size);
		char_size++;
		if (char_size == 8)
		{
			line[i - 1] = c;
			c = 0;
			if (line[i - 1] == '\0')
			{
				ft_printf("%s\n", line);
				i = 0;
				free(line);
			}
			else
			{
				i++;
			}
			char_size = 0;
		}
	}
}

char	*biggerline(char *line)
{
	int		i;
	char	*bigline;

	i = ft_strlen(line) + 1000;
	bigline = malloc(i * sizeof(char));
	ft_strlcpy(bigline, line, i);
	free (line);
	return (bigline);
}

char	reconstruct(char c, int char_size)
{
	c |= 1 << char_size;
	return (c);
}

int	find_len(int n, int char_size)
{
	n |= 1 << char_size;
	return (n);
}
