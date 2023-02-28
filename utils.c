/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:32:54 by cmois             #+#    #+#             */
/*   Updated: 2023/02/28 14:10:36 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

void    ft_putchar(t_conversion *what, char c)
{
    write(1, &c, 1);
    what->_totalLen ++;
}

void    ft_putstr(t_conversion *what, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(what, str[i]);
        i++;
    }
}

void    ft_putnbr(t_conversion *what, long long nbr)
{
	if (nbr < 0)
	{
		ft_putchar(what, '-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(what, nbr / 10);
		ft_putnbr(what, nbr % 10);
	}
	else
		ft_putchar(what, (nbr + 48));
}