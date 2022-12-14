/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:15:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/10/18 10:25:59 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 1
# define _XOPEN_SOURCE 500

# include "ft_printf.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# ifdef __MACH__
#  define TIME 400
# elif __APPLE__
#  define TIME 200
# elif __linux__
#  define TIME 500
# endif

# define MIX_PID 4194304

/*SERVER*/
void		ft_handler(int signo);
char		reconstruct(char c, int char_size);
int			add_len(int n, int char_size);
int			find_len(int *i, int *len, int *char_size, char **line);
int			endchar(char *line, char *c, int *i, int *len);
int			ft_isprint(int c);

/*CLIENT*/
long int	ft_atoi(char *str);
long int	check_pid(char *pid);
void		send(char c, int pid);
void		send_len(int len, int pid);

#endif