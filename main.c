/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:41 by cmois             #+#    #+#             */
/*   Updated: 2023/02/28 14:15:25 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"




int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int test;

    test = 4;
    printf("test : %p\n", &test);
    
    ft_printf(" my test : %p\n", &test);
    return (0);
}