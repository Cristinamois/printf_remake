/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobDoneHere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:28 by cmois             #+#    #+#             */
/*   Updated: 2023/03/01 13:35:29 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"


void    whoIsIt(t_conversion *what, char c)
{
    if (c == C)
    {
        what->_ifChar = va_arg(what->paramInfo, int);
        what->_argLen = 1;
        what->_ARGNBR -= what->_argLen;
        if (what->_isMinus == true)
        {
            ft_putchar(what, what->_ifChar);
            for (int i = 0; i < what->_ARGNBR; i++)
                ft_putchar(what, ' ');
        }
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        resetToOrigin(what);
        if (what->_isMinus == false)
            ft_putchar(what, what->_ifChar);
        what->_isMinus = false;
    }
    if (c == S)
    {
        what->_ifStr = (char*)va_arg(what->paramInfo, char *);
        what->_argLen = argLenStr(what->_ifStr, what);
        what->_ARGNBR -= what->_argLen;
        if (what->_isMinus == true)
        {
            ft_putstr(what, what->_ifStr);
            for (int i = 0; i < what->_ARGNBR; i++)
                ft_putchar(what, ' ');
        }
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        if (what->_isMinus == false)
            ft_putstr(what, what->_ifStr);
        what->_isMinus = false;
        resetToOrigin(what);
    }
    if (c == 'd' || c == I)
    {
        what->_ifNumber = (int)va_arg(what->paramInfo, int);
        what->_argLen = argLenInt(what->_ifNumber, what);
        what->_ARGNBR -= what->_argLen;
        if (what->_isMinus == true)
        {
            ft_putnbr(what, what->_ifNumber);
            if (what->_ifNumber == 0)
                what->_ARGNBR -= 1;
            for (int i = 0; i < what->_ARGNBR; i++)
                ft_putchar(what, ' ');
        }
        if (what->_isPlus == true)
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
        if (what->_isZero == true)
        {
            ft_putchar(what, '-');
            what->_ARGNBR -= 1;
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, '0');
            }
        }
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        if (what->_isMinus == false)
            ft_putnbr(what, what->_ifNumber);
        what->_isZero = false;
        what->_isPlus = false;
        what->_isMinus = false;
    }
    if (c == P || c == x || c == X)
    {
        if (c == P)
        {
            what->_ifNumber = (long long)va_arg(what->paramInfo, long long);
            what->_argLen = argLenInt(what->_ifNumber, what);
            what->_ARGNBR -= what->_argLen;
            // printf("arglen : {%d}\targnbr : {%d}\n", what->_argLen, what->_ARGNBR);
            if (what->_isMinus == true)
            {
                treatHexa(what, c);
                for (int i = 0; i < what->_ARGNBR + 1; i++)
                    ft_putchar(what, ' ');
            }
            if (what->_isSpace == true)
            {
                for (int i = 0; i < what->_ARGNBR; i++)
                {
                    ft_putchar(what, ' ');
                }
                what->_isSpace = false;
            }
        }
        if (c == x || c == X)
        {
            what->_ifNumber = (unsigned int)va_arg(what->paramInfo, unsigned int);
            what->_argLen = argLenUInt(what->_ifNumber, what);
            what->_ARGNBR -= what->_argLen;
            if (what->_hashtag == true)
            {
                what->_ARGNBR -= 2;
                for (int i = 0; i < what->_ARGNBR; i++)
                    ft_putchar(what, ' ');
                ft_putstr(what, "0x");
            }
            if (what->_isMinus == true)
            {
               treatHexa (what, c);
                for (int i = 0; i < what->_ARGNBR; i++)
                    ft_putchar(what, ' ');
            }
            if (what->_isZero == true)
            {
                for (int i = 0; i < what->_ARGNBR; i++)
                {
                    ft_putchar(what, '0');
                }
            }
            if (what->_isSpace == true)
            {
                for (int i = 0; i < what->_ARGNBR; i++)
                {
                    ft_putchar(what, ' ');
                }
                what->_isSpace = false;
            }
        }
        if (what->_isMinus == false)
            treatHexa(what, c);
        what->_isZero = false;
        what->_isMinus = false;
        what->_hashtag = false;
    }
    if (c == U)
    {
        what->_ifNumber = (unsigned int)va_arg(what->paramInfo, unsigned int);
        what->_argLen = argLenUInt(what->_ifNumber, what);
        what->_ARGNBR -= what->_argLen;
        if (what->_isMinus == true)
        {
            ft_putnbr(what, what->_ifNumber);
            for (int i = 0; i < what->_ARGNBR; i++)
                ft_putchar(what, ' ');
        }
        if (what->_isZero == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, '0');
            }
        }
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        if (what->_isMinus == false)
            ft_putnbr(what, what->_ifNumber);
        what->_isZero = false;
        what->_isMinus = false;
    }
    if (c == '%')
    {
        what->_argLen = 1;
        what->_ARGNBR -= what->_argLen;
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        ft_putchar(what, c);
    }
        

}

void doTheJob(t_conversion *what, char c)
{
    if (c == C || c == S || c == P || c == D || c == I || c == U || c == x || c == X || c == '%')
        whoIsIt(what, c);
}