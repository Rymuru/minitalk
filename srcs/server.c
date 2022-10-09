/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/09 06:44:30 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois recuperer le pid et l'afficher*/
/*je dois recevoir la chaine de caractere d'un client a la fois et l'afficher*/

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
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
	static int			i;
	static int			char_size;
	static char			*line;

	i = 0;
	char_size = 0;
	if (i == 0 && char_size == 0)
		line = malloc(1000 * (sizeof(char)));
	if (ft_strlen(line + 1) == '\0')
		line = biggerline(line);
	line[i] = reconstruct(signo, line[i]);
	char_size++;
	if (char_size == 7)
	{
		if (line[i] == '\0')
		{
			ft_printf(line);
			free(line);
		}
		i++;
		char_size = 0;
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

char	reconstruct(int signo, char c)
{
	int	new;

	if (signo == SIGUSR2)
		new = 1;
	else
		new = 0;
	c = c * 2;
	c = c + new;
	return (c);
}
