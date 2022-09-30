/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:15:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/09/30 20:38:13 by bcoenon          ###   ########.fr       */
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

# define MIX_PID 4194304

# define DELAY 15

/*SERVER*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*handler(int n, int *i, char *line, int *char_size);
char	*biggerline(char *line);
char	reconstruct(int signo, char c);

#endif