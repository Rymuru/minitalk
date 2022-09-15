/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:45:45 by bcoenon           #+#    #+#             */
/*   Updated: 2021/11/24 10:10:21 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scrs/ft_printf.h"
#include <stdio.h>

int main()
{
    printf("LE VRAI PRINTF DIT : %d\n", printf("%s", "coucou biloute caca\n"));
    printf("MON PRINTF TOUT BO TOUT CHO DIT : %d\n", ft_printf("%s", "coucou biloute caca\n"));

    printf("===========================================================\n");

    printf("LE VRAI PRINTF DIT : %d\n", printf("%s", ""));
    printf("MON PRINTF TOUT BO TOUT CHO DIT : %d\n", ft_printf("%s", ""));

    printf("===========================================================\n");

    printf("LE VRAI PRINTF DIT : %d\n", printf("%X", 16));
    printf("MON PRINTF TOUT BO TOUT CHO DIT : %d\n", ft_printf("%X", 16));
    return (0);
}

