/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:24:37 by cmois             #+#    #+#             */
/*   Updated: 2023/03/01 12:23:17 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

void    structInit(t_conversion *what)
{
    what->_ifStr = NULL;
    what->_ifPointer = 0;
    what->_ifNumber = 0;
    what->_totalLen = 0;
    what->_isSpace = false;
    what->_isZero = false;
    what->_argLen = 0;
    what->_ARGVAL = (char *)malloc(sizeof(char) * 11);
    ft_bzero(what->_ARGVAL);
    what->_count = 0;
    what->_ARGNBR = 0;
    what->_isPlus = false;
    what->_isMinus = false;
    
}

int ft_printf(const char *str, ...)
{
    t_conversion   *what;
    int             returnValue;

    what = (t_conversion *)malloc(sizeof(t_conversion));
    if (!what)
        return (MALLOC_ERROR);
    returnValue = 0;
    structInit(what);
    va_start(what->paramInfo, str);
    parser(what, str);
    
    returnValue = what->_totalLen;
    free(what->_ARGVAL);
    free(what);
    printf("ret val : %d\n", returnValue);
    return (returnValue);
}