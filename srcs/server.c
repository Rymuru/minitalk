/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/03 16:33:02 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois recuperer le pid et l'afficher*/
/*je dois recevoir la chaine de caractere d'un client a la fois et l'afficher*/

#include "minitalk.h"

int	main(void)
{
	int		i;
	int		pid;
	int		char_size;
	char	*line;

	i = 0;
	pid = getpid();
	char_size = 0;
	ft_printf("%d\n", pid);
	line = malloc(1000 * (sizeof(char)));
	line[999] = '\0';
	signal(SIGUSR1, handler(0, &i, line, &char_size));
	signal(SIGUSR2, handler(1, &i, line, &char_size));
	while (1)
		pause();
	return (0);
}

/*un signal = un bit*/
/*donc il va falloir reconstituer les caracteres a l'arrivee*/

void	*handler(int n, int *i, char *line, int *char_size)
{
	if (ft_strlen(line + 1) == '\0')
		line = biggerline(line);
	line[*i] = reconstruct(n, line[*i]);
	(*char_size)++;
	if (*char_size == 7)
	{
		if (line[*i] == '\0')
		{
			ft_printf(line);
			free(line);
			return (0);
		}
		(*i)++;
		*char_size = 0;
	}
	return (0);
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
	c = c * 2;
	c = c + signo;
	return (c);
}
