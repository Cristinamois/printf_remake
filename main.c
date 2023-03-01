/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:41 by cmois             #+#    #+#             */
/*   Updated: 2023/03/01 12:42:06 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"




int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    // int test;
    
    // test = 42;
    char *str;
    str = "lollll";
    printf("test : [%c] [%-7s] [%-20p] [%d] [%i] [%u] [%x] [%X] [%%] \n", 'c', str, &str, 0, 0, 94, 42, 42);
    
    ft_printf("temt : [%c] [%-7s] [%-20p] [%d] [%i] [%u] [%x] [%X] [%%] \n", 'c', str, &str, 0, 0, 94, 42, 42);
    
    //- flag with :             c   s   p   d   i   u   x   X
    
    // ft_printf("\n\n\n %d\n", -789);
    return (0);
}