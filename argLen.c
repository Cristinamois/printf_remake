/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argLen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:48:41 by cmois             #+#    #+#             */
/*   Updated: 2023/02/28 15:18:26 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

int argLenStr(char *str, t_conversion *what)
{
    int i;
    
    (void)what;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int argLenUInt(unsigned int nbr, t_conversion *what)
{
    int ret;
    (void)what;

    ret = 0;
    if (nbr)
    {
        while (nbr / 10)
        {
            argLenUInt(nbr, what);
            ret++;
        }
    }
    return (ret);
}

int argLenInt(long long nbr, t_conversion *what)
{
    int ret;

    (void)what;
    ret = 0;
    if (nbr)
    {
        while (nbr / 10)
        {
            argLenUInt(nbr, what);
            ret++;
        }
    }
    return (ret);
}