/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaAll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:07:54 by cmois             #+#    #+#             */
/*   Updated: 2023/03/02 11:48:06 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

void	putHexa(t_conversion *what, long long nbr, char c)
{
	if (nbr >= 16)
	{
		putHexa(what, (nbr / 16), c);
		putHexa(what, (nbr % 16), c);
	}
	else
	{
		if (c == 'x')
			ft_putchar(what, BASE16_MIN[nbr]);
		if (c == 'X')
			ft_putchar(what, BASE16_MAJ[nbr]);
	}
}

void	putPointer(t_conversion *what, long long nbr)
{
	if (nbr >= 16)
	{
		// printf("nbr : %lld\n", nbr);
		putPointer(what, (nbr / 16));
		putPointer(what, (nbr % 16));
	}
	else
		ft_putchar(what, BASE16_MIN[nbr]);
}

void    treatHexa(t_conversion *what, char c)
{
    if (c)
    {
        ft_putstr(what, "0x");
        putPointer(what, what->_ifNumber);
    }
    if (c == x || c == X)
        putHexa(what, what->_ifNumber, c);
}