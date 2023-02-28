/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobDoneHere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:28 by cmois             #+#    #+#             */
/*   Updated: 2023/02/28 15:10:07 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"


void    whoIsIt(t_conversion *what, char c)
{
    if (c == C)
    {
        what->_ifChar = va_arg(what->paramInfo, int);
        what->_argLen = 1;
        if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        ft_putchar(what, what->_ifChar);
    }
    if (c == S)
    {
        what->_ifStr = va_arg(what->paramInfo, char *);
        what->_argLen = argLenStr(what->_ifStr, what);
        if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        ft_putstr(what, what->_ifStr);
    }
    if (c == 'd' || c == I)
    {
        what->_ifNumber = va_arg(what->paramInfo, long long);
        what->_argLen = argLenInt(what->_ifNumber, what);
        if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        ft_putnbr(what, what->_ifNumber);
    }
    if (c == P || c == x || c == X)
    {
        if (c == P)
        {
            what->_ifNumber = va_arg(what->paramInfo, long long);
            what->_argLen = argLenInt(what->_ifNumber, what);
            if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        }
        if (c == x || c == X)
        {
            what->_ifNumber = va_arg(what->paramInfo, unsigned int);
            what->_argLen = argLenInt(what->_ifNumber, what);
            if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        }
        treatHexa(what, c);
    }
    if (c == U)
    {
        what->_ifNumber = va_arg(what->paramInfo, unsigned int);
        what->_argLen = argLenUInt(what->_ifNumber, what);
        if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        ft_putchar(what, what->_ifNumber);
    }
    if (c == '%')
    {
        what->_argLen = 1;
        if (what->_isSpace == true)
        {
            int howMuch;
            howMuch = atoi(what->_ARGVAL) - what->_argLen;
            for (int i = 0; i < howMuch; i++)
            {
                ft_putchar(what, ' ');
                i++;
            }
        }
        ft_putchar(what, c);
    }
        

}

void doTheJob(t_conversion *what, char c)
{
    if (c == C || c == S || c == P || c == D || c == I || c == U || c == x || c == X || c == '%')
        whoIsIt(what, c);
}