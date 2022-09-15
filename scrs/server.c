/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:49 by bcoenon           #+#    #+#             */
/*   Updated: 2022/09/15 17:05:50 by bcoenon          ###   ########.fr       */
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
}

/*un signal = un bit*/
/*donc il va falloir reconstituer les caracteres a l'arrivee*/
