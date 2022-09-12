/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:14:44 by bcoenon           #+#    #+#             */
/*   Updated: 2022/09/12 19:37:01 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois prendre en entree le PID du serveur et la chaine de caracteres*/
/*je dois envoyer la chaine de cracteres au serveur*/

/* 1: verification de la validite du pid*/
/* 2: verification de la validite de la chaine*/

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	if (check_pid(av[1] != 0))
		return (1);
}

/*need to check if only numbers, and min and max value*/

int	check_pid(char *pid)
{
	
}
