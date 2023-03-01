/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:41 by cmois             #+#    #+#             */
/*   Updated: 2023/03/01 09:43:16 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"




int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int test;
    
    test = 42789879;
    char *str;
    str = "lol";
    printf("test : [% 100d] [%x] [%%] [%s]\n", 64, test, str);
    
    ft_printf("temt : [% 100d] [%x] [%%] [%s]\n", 64, test, str);
    return (0);
}