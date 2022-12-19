/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:26 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/19 18:06:32 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    // Define a struct da mesa
    t_rules rules;

    // Checa se os argumentos estão corretos
    if (!check(argc, argv))
        return (0);

    // Inicia o jantar
    init(argv, &rules);

    // Encerrar o jantar
    finish(&rules);

    return 0;
}
