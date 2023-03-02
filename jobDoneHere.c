/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobDoneHere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:28 by cmois             #+#    #+#             */
/*   Updated: 2023/03/02 11:55:22 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

bool    isThereFormat(t_conversion *what)
{
    if (what->_isSpace == true || what->_isZero == true || what->_isPlus == true || what->_isMinus == true || what->_hashtag == true)
        return (true);
    return (false);
}

void    whoIsIt(t_conversion *what, char c)
{
    if (c == C)
    {
        what->_ifChar = va_arg(what->paramInfo, int);
        what->_argLen = 1;
        what->_ARGNBR -= what->_argLen;
        if (isThereFormat(what))
            treatFormat(what, 1);
        if (what->_isMinus == false)
            ft_putchar(what, what->_ifChar);
        resetToOrigin(what);
    }
    if (c == S)
    {
        what->_ifStr = (char*)va_arg(what->paramInfo, char *);
        what->_argLen = argLenStr(what->_ifStr, what);
        what->_ARGNBR -= what->_argLen;
        if (isThereFormat(what))
            treatFormat(what, 2);
        if (what->_isMinus == false)
            ft_putstr(what, what->_ifStr);
        resetToOrigin(what);
    }
    if (c == 'd' || c == I)
    {
        what->_ifNumber = (int)va_arg(what->paramInfo, int);
        what->_argLen = argLenInt(what->_ifNumber, what);
        what->_ARGNBR -= what->_argLen;
        if (isThereFormat(what))
            treatFormat(what, 3);
        if (what->_isMinus == false)
            ft_putnbr(what, what->_ifNumber);
        resetToOrigin(what);
    if (c == P || c == x || c == X)
    {
        what->_actual = c;
        if (c == P)
        {
            what->_ifNumber = (long long)va_arg(what->paramInfo, long long);
            what->_argLen = argLenInt(what->_ifNumber, what);
            what->_ARGNBR -= what->_argLen;
            // printf("arglen : {%d}\targnbr : {%d}\n", what->_argLen, what->_ARGNBR);
            if (isThereFormat(what))
                treatFormat(what, 4);
        }
        if (c == x || c == X)
        {
            what->_ifNumber = (unsigned int)va_arg(what->paramInfo, unsigned int);
            what->_argLen = argLenUInt(what->_ifNumber, what);
            what->_ARGNBR -= what->_argLen;
            if (isThereFormat(what))
                treatFormat(what, 4);
        }
        if (what->_isMinus == false)
            treatHexa(what, c);
        resetToOrigin(what);
    }
    if (c == U)
    {
        what->_ifNumber = (unsigned int)va_arg(what->paramInfo, unsigned int);
        what->_argLen = argLenUInt(what->_ifNumber, what);
        what->_ARGNBR -= what->_argLen;
        if (isThereFormat(what))
            treatFormat(what, 3);
        if (what->_isMinus == false)
            ft_putnbr(what, what->_ifNumber);
        resetToOrigin(what);
    }
    if (c == '%')
    {
        what->_argLen = 1;
        what->_ARGNBR -= what->_argLen;
        if (isthereFormat(what))
            treatFormat(what, 0);
        ft_putchar(what, c);
        resetToOrigin(what);
    }
        

}

void doTheJob(t_conversion *what, char c)
{
    if (c == C || c == S || c == P || c == D || c == I || c == U || c == x || c == X || c == '%')
        whoIsIt(what, c);
}