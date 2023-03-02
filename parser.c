/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:29:47 by cmois             #+#    #+#             */
/*   Updated: 2023/03/02 11:04:13 by cmois            ###   ########.fr       */
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

bool    isItWhatWeWant(t_conversion *what, const char *str, int i)
{
    if ((str[i] == ' ' && (str[i + 1] >= '0' && str[i + 1] <= '9')) || (str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
                || (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')) || (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
                || (str[i] == '#' && (str[i + 1] >= '0' && str[i + 1] <= '9')) || str[i] == '#' || str[i] == '+')
    {
        if (str[i] == '#')
             what->_hashtag = true;
        if (str[i] == '-')
            what->_isMinus = true;
        if (str[i] == '+')
             what->_isPlus = true;                                                                           //ERROR CHECK FOR ARGS
        if (str[i] == ' ')
            what->_isSpace = true;
        if (str[i] == '0')
             what->_isZero = true;
        return (true);
    }
    return (false);
}

// void    getNumbers(const char *str, int i, t_conversion *what)
// {
//     while (str[i] >= '0' && str[i] <= '9')
//     {
//         what->_ARGVAL = joinNumbers(what, str[i]);
//         i++;
//     }
// }


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
            if (isItWhatWeWant(what, str, i))
            {
                i++;
                // getNumbers(str, i, what);
                while (str[i] >= '0' && str[i] <= '9')
                {
                    what->_ARGVAL = joinNumbers(what, str[i]);
                    i++;
                }
                what->_ARGNBR = atoi(what->_ARGVAL);
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
    }
}