/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:41 by cmois             #+#    #+#             */
/*   Updated: 2023/02/28 15:18:42 by cmois            ###   ########.fr       */
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
    printf("test : %x %% %s\n|% 7d\n", test, str, 789);
    
    ft_printf(" my test : %x %% %s\n", test, str);
    return (0);
}