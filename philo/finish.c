/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:59 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/19 18:14:43 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que aguarda as threads dos filósofos terminarem
void finish(t_rules *table)
{
    int i = 0;

    // Aguarda as threads dos filósofos terminarem
    while (i < table->num_philosophers)
        pthread_join(table->philo[i++].thread, NULL);

    // Limpa os mutexes dos garfos
    i = 0;
    while (i < table->num_philosophers)
        pthread_mutex_destroy(&table->forks[i++]);

    // Libera a memória alocada
    free(table->philo);
    free(table->forks);
}