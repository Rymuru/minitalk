/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/28 18:19:12 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*le main recupere et affiche le pid puis fait appel au handler*/

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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = blocked;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error.\n", 7);
		return (42);
	}
	while (1)
		pause();
	return (0);
}

/*cette fonction prends en charge les signaux*/
/*elle fait usage de beaucoup de statiques*/
/*car toutes ces valeurs doivent etre conservees entre deux signaux*/

void	ft_handler(int signo)
{
	static int		char_size = 0;
	static int		len = 0;
	static int		i = 0;
	static char		c = 0;
	static char		*line;

	if (i == 0)
	{
		if (signo == SIGUSR2)
			len = add_len(len, char_size);
		find_len(&i, &len, &char_size, &line);
	}
	else
	{
		if (signo == SIGUSR2)
			c = reconstruct(c, char_size);
		char_size++;
		if (char_size == 8)
		{
			endchar(line, &c, &i, &len);
			char_size = 0;
		}
	}
}

/*cette fonction permet de determiner la longueur de la string transmise*/
/*et ainsi de malloc la longueur correspondante*/

int	find_len(int *i, int *len, int *char_size, char **line)
{
	(*char_size)++;
	if (*char_size == 32)
	{
		if ((*len) > 0)
			*line = malloc(((*len) + 1) * sizeof(char));
		if (!*line)
		{
			(*char_size) = 8;
			(*len) = 0;
			return (1);
		}
		else
			(*char_size) = 0;
		(*i)++;
	}
	return (0);
}

/*cette fonction determine que faire une fois un char reconstitue*/

int	endchar(char *line, char *c, int *i, int *len)
{
	if (ft_isprint(*c) == 0)
		(*i) = (*len) + 1;
	line[(*i) - 1] = (*c);
	(*c) = 0;
	if (!line || line[(*i) - 1] == '\0' || (*i) - 1 == *len)
	{
		if (line && line[(*i) - 1] == '\0' && (*i) - 1 == *len)
			ft_printf("%s\n", line);
		else
		{
			write(2, "error\n", 7);
			sleep(5);
		}
		(*i) = 0;
		(*len) = 0;
		free(line);
	}
	else
	{
		(*i)++;
	}
	return (0);
}
