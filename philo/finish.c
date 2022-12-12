/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:59 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/12 20:13:00 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que aguarda as threads dos filósofos terminarem
void finish(t_table table)
{
    int i = 0;
    int num_philosophers = table.num_philosophers;

    // Aguarda as threads dos filósofos terminarem
    while (i < num_philosophers)
    {
        pthread_join(table.philo[i].thread, NULL);
        i++;
    }

    // Limpa os mutexes dos garfos
    while (i < num_philosophers)
    {
        pthread_mutex_destroy(&table.forks[i]);
        i++;
    }

    // Libera a memória alocada
    free(table.philo);
    free(table.forks);
}