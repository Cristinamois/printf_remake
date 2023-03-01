/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:32:54 by cmois             #+#    #+#             */
/*   Updated: 2023/03/01 09:55:06 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_printf.h"

void    ft_putchar(t_conversion *what, char c)
{
    write(1, &c, 1);
    what->_totalLen ++;
}

void    ft_putstr(t_conversion *what, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(what, str[i]);
        i++;
    }
}

void    ft_putnbr(t_conversion *what, long long nbr)
{
	if (nbr < 0)
	{
		ft_putchar(what, '-');
		// printf("goes here\n");
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(what, nbr / 10);
		ft_putnbr(what, nbr % 10);
	}
	else
		ft_putchar(what, (nbr + 48));
}

int	toINT(char c)
{
	int ret;

	ret = c - 48;
	return (ret);
}

void	ft_bzero(char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = '0';
		i++;
	}
}

char	*joinNumbers(t_conversion *what, char c)
{
	char *ret;
	int i;

	i = 0;
	ret = what->_ARGVAL;
	ret[i + what->_count] = c;
	what->_count++;
	return (ret);
}

// char	*joinNumbers(t_conversion *what, char c)
// {
// 	int 	i;
// 	char	*ret;

// 	ret = what->_ARGVAL;
// 	i = 0;
// 	while (ret[i] != '\0')
// 	{
// 		if (ret[i + 1] == '\0')
// 		{
// 			ret = (char *)malloc(sizeof(char) * 1);
// 			i++;
// 			ret[i] = c;
// 		}
// 		if (ret[i] != '\0')
// 			i++;
// 	}
// 	return (ret);
// }

//function 

// char	*ft_strjoin(char *s1, char c)
// {
// 	char		*str;
// 	size_t		i;
// 	size_t		j;

// 	if (s1 == NULL || !c)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * strlen(s1) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		str[j++] = s1[i];
// 		i++;
// 	}
//     str[j] = c;
// 	return (str);
// }