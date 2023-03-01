/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobDoneHere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:28 by cmois             #+#    #+#             */
/*   Updated: 2023/03/01 10:07:48 by cmois            ###   ########.fr       */
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
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        resetToOrigin(what);
        ft_putchar(what, what->_ifChar);
    }
    if (c == S)
    {
        what->_ifStr = (char*)va_arg(what->paramInfo, char *);
        what->_argLen = argLenStr(what->_ifStr, what);
        what->_ARGNBR -= what->_argLen;
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        
        ft_putstr(what, what->_ifStr);
    }
    if (c == 'd' || c == I)
    {
        what->_ifNumber = (int)va_arg(what->paramInfo, int);
        // printf("number : {%lld}\n", what->_ifNumber);
        what->_argLen = argLenInt(what->_ifNumber, what);
        what->_ARGNBR -= what->_argLen;
        // printf("argVAL : {%s}\n", what->_ARGVAL);
        if (what->_ifNumber < 0)
            what->_ARGNBR -= 1;
        if (what->_isSpace == true)
        {
            // printf("argval : %c\n", what->_ARGNBR);
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        ft_putnbr(what, what->_ifNumber);
    }
    if (c == P || c == x || c == X)
    {
        if (c == P)
        {
            what->_ifNumber = (long long)va_arg(what->paramInfo, long long);
            what->_argLen = argLenInt(what->_ifNumber, what);
            what->_ARGNBR -= what->_argLen;
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
            if (what->_isSpace == true)
            {
                for (int i = 0; i < what->_ARGNBR; i++)
                {
                    ft_putchar(what, ' ');
                }
                what->_isSpace = false;
            }
        }
        treatHexa(what, c);
    }
    if (c == U)
    {
        what->_ifNumber = (unsigned int)va_arg(what->paramInfo, unsigned int);
        what->_argLen = argLenUInt(what->_ifNumber, what);
        what->_ARGNBR -= what->_argLen;
        if (what->_isSpace == true)
        {
            for (int i = 0; i < what->_ARGNBR; i++)
            {
                ft_putchar(what, ' ');
            }
            what->_isSpace = false;
        }
        ft_putnbr(what, what->_ifNumber);
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