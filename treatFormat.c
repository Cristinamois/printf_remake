/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatFormat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:52:21 by cmois             #+#    #+#             */
/*   Updated: 2023/03/02 11:51:00 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

void    treatSpace(t_conversion *what)
{
    for (int i = 0; i < what->_ARGNBR; i++)
    {
        ft_putchar(what, ' ');
    }
}

void    treatMinus(t_conversion *what, int rep)
{
    if (what->_isMinus == true && rep == 1)
    {
        ft_putchar(what, what->_ifChar);
        for (int i = 0; i < what->_ARGNBR; i++)
            ft_putchar(what, ' ');
    }
    if (what->_isMinus == true && rep == 2)
    {
        ft_putstr(what, what->_ifStr);
        for (int i = 0; i < what->_ARGNBR; i++)
            ft_putchar(what, ' ');
    }
    if (what->_isMinus == true && rep == 3)
    {
        ft_putnbr(what, what->_ifNumber);
        if (what->_ifNumber == 0)
            what->_ARGNBR -= 1;
        for (int i = 0; i < what->_ARGNBR; i++)
            ft_putchar(what, ' ');
    }
    if (what->_isMinus == true && rep == 4)
    {
        treatHexa(what, what->_actual);
        for (int i = 0; i < what->_ARGNBR + 1; i++)
             ft_putchar(what, ' ');
    }
}

void    treatPlus(t_conversion *what)
{
    if (what->_ifNumber == 0)
    {
        for (int i = 0; (i < what->_ARGNBR - 2); i++)
            ft_putchar(what, ' ');
        ft_putchar(what, '+');
    }
    if (what->_ifNumber > 0)
    {
        for (int i = 0; (i < what->_ARGNBR - 1); i++)
             ft_putchar(what, ' ');
        ft_putchar(what, '+');
    }
    if (what->_ifNumber < 0)
        for (int i = 0; i < what->_ARGNBR - 1; i++)
            ft_putchar(what, ' ');
}

void    treatZero(t_conversion *what)
{
    if (what->_ifNumber < 0)
    {
        ft_putchar(what, '-');
        what->_ARGNBR -= 1;
    }
    for (int i = 0; i < what->_ARGNBR; i++)
    {
        ft_putchar(what, '0');
    }
}

void    treatHashtag(t_conversion *what)
{
    what->_ARGNBR -= 2;
    for (int i = 0; i < what->_ARGNBR; i++)
        ft_putchar(what, ' ');
    ft_putstr(what, "0x");
}

void    treatFormat(t_conversion *what, int rep)
{
    if (what->_isSpace == true)
        treatSpace(what);
    if (what->_isMinus == true)
        treatMinus(what, rep);
    if (what->_isPlus == true)
        treatPlus(what);
    if (what->_isZero == true)
        treatZero(what);
    if (what->_hashtag ==true)
        treatHashtag(what);
        
}