/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:26 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/13 21:27:43 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    // Define a struct da mesa
    t_table table;

    // Checa se os argumentos estão corretos
    if (!check(argc, argv))
        return (0);

    // Inicia o jantar
    table = init(argc, argv);

    // Encerrar o jantar
    finish(table);

    return 0;
}
