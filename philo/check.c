/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:32 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/13 21:27:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check(int argc, char **argv)
{
    long int value;
    int flag;
    int i;
    int j;

    // Checa se o número de argumentos está correto
    if (argc < 5 || argc > 6)
    {
        help_msg();
        return (0);
    }

    // Checa se os argumentos são válidos
    // Verificar se os negativos são aceitos
    i = 0;
    flag = 1;
    while (argv[++i])
    {
        j = 0;
        value = ft_atoi_l(argv[i]);
        if (value < INT_MIN || value > INT_MAX)
            flag = 0;
        if (ft_issign(argv[i][j]) && argv[i][j + 1] != '\0')
        {
            flag = 0;
            j++;
        }
        while (argv[i][j] && ft_isdigit(argv[i][j]))
            j++;
        if (argv[i][j] != '\0' && !ft_isdigit(argv[i][j]))
            flag = 0;
    }
    if (!flag)
        error_msg();
    return (flag);
}