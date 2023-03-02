/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:41 by cmois             #+#    #+#             */
/*   Updated: 2023/03/02 11:42:52 by cmois            ###   ########.fr       */
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
    str = "salut les loulous";
    printf("test : [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%] \n", 'c', str, &str, -489456, 0, 94, 42, 42);
    
    ft_printf("temt : [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%] \n", 'c', str, &str, -489456, 0, 94, 42, 42);
    
    // 
    printf("here is a float : %o \n", 4789789);
    //- flag with :             c   s   p   d   i   u   x   X
    
    // ft_printf("\n\n\n %d\n", -789);
    return (0);
}