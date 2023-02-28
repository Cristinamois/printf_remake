/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:29:47 by cmois             #+#    #+#             */
/*   Updated: 2023/02/28 15:17:36 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

int isItConvertible(char c)
{
    if (c == C || c == S || c == P || c == D || c == I
        || c == U || c == x || c == X || c == '%')
        return (1);
    return (0);
}


void    parser(t_conversion *what, const char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (isItConvertible(str[i]))
            {
                doTheJob(what, str[i]);
                i++;
            }
            if (str[i] == ' ' && (str[i + 1] >= 0 && str[i + 1] <= 9))
            {
                what->_isSpace = true;
                i++;
                if (isItConvertible(str[i]))
                {
                    doTheJob(what, str[i]);
                    i++;
                }
            }
        }
        else
        {
            ft_putchar(what, str[i]);
            i++;
        }
        // i++;
    }
}