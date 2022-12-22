/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:59 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 14:58:24 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que aguarda as threads dos filósofos terminarem
void finish(t_rules *rules)
{
    int i = 0;

    // Aguarda as threads dos filósofos terminarem
    while (i < rules->num_philosophers)
        pthread_join(rules->philo[i++].thread, NULL);

    // Limpa os mutexes dos garfos
    i = 0;
    while (i < rules->num_philosophers)
        pthread_mutex_destroy(&rules->forks[i++]);

    // Libera a memória alocada
    free(rules->philo);
    free(rules->forks);
}